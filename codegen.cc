#include <string>
#include "pstcode.h"
#include "codegen.h"
using namespace std;

extern int global_count_loc;

PstackCode CodeGen::generate(Visitable *vis)
{
    vis->accept(this);
    return code;
}

void CodeGen::visitProg(Prog *prog)
{
    code.begin_prog();
    code.prolog(symbols);

    // Insert call to main(), to be patched up later.
    code.add(I_CALL);
    int patchloc = code.pos();
    code.add(0);
    code.add(0);
    code.add(I_ENDPROG);

    // Generate code for the functions.
    prog->listfunction_->accept(this);

    // Now look up the address of main, and throw if it wasn't defined.
    if (!symbols.exists("main"))
        throw UnknownFunc("main");
    int level = symbols.levelof("main");
    int addr = symbols["main"]->address();

    // Patch up the address of main.
    code.at(patchloc) = level;
    code.at(patchloc + 1) = addr;

    code.end_prog();
}
void CodeGen::visitGlobal(Global *global){
  global->type_->accept(this);
  visitIdent(global->ident_); // sets currid
  symbols.insert(Symbol(currid, currtype, 3 + symbols.numvars()));
  code.at(global_count_loc) = symbols.numvars();
}

void CodeGen::visitFun(Fun *fun)
{
    fun->type_->accept(this);
    // return type in currtype, but currently ignored (always int)

    visitIdent(fun->ident_);
    Ident fun_name = currid;

    if (symbols.exists(fun_name))
        throw Redeclared(fun_name);

    int funcloc = code.pos();

    code.add(I_PROC);
    int patchloc = code.pos(); // to be filled with number of local variables.
    code.add(0);
    code.add(code.pos() + 1); // function code starts next

    symbols.enter(); // since parameters are local to the function
    // Adds entries to symbol table, sets funargs
    fun->listdecl_->accept(this);
    int startvar = symbols.numvars();

    // Generate code for function body.
    fun->liststm_->accept(this);

    // Fill in number of local variables.
    code.at(patchloc) = symbols.numvars() - startvar;
    symbols.leave();

    // Return, popping off our parameters.
    code.add(I_ENDPPROC);
    code.add(funargs);

    symbols.insert(Symbol(fun_name, curr_arg_list_types, funcloc));
}

void CodeGen::visitDec(Dec *dec)
{
    dec->type_->accept(this); // sets currtype
    dec->listident_->accept(this); // visitListIdent; uses currtype
}

void CodeGen::visitSDecl(SDecl *sdecl)
{
    sdecl->decl_->accept(this); // visitDec
}

void CodeGen::visitSExp(SExp *sexp)
{
    sexp->exp_->accept(this);

    // Pop and discard the expression's value.  pstack doesn't have a
    // POP instruction, but a conditional jump to the next instruction
    // (PC + 2) will do the trick.
    code.add(I_JR_IF_TRUE);
    code.add(2);
}

void CodeGen::visitSBlock(SBlock *sblock)
{
    sblock->liststm_->accept(this);
}

void CodeGen::visitSWhile(SWhile *swhile)
{
    int looploc = code.pos(); // Beginning of test
    swhile->exp_->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    swhile->stm_->accept(this); // Body.
    code.add(I_JR);
    code.add(looploc - (code.pos() - 1)); // offset to looploc
    code.at(patchloc) = code.pos() - (patchloc - 1);
}

void CodeGen::visitSRepeat(SRepeat *srepeat)
{
    int looploc = code.pos(); // Beginning of code

    srepeat->stm_->accept(this); // Body.

    srepeat->exp_->accept(this); // Test
    code.add(I_JR_IF_FALSE);  // Jump to the body.

    int offset = looploc - (code.pos() - 1);
    code.add(offset);
}

void CodeGen::visitSIf(SIf *sif)
{
    sif->exp_->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    sif->stm_->accept(this); // Body.
    code.at(patchloc) = code.pos() - (patchloc - 1);
}

void CodeGen::visitSIfThen(SIfThen *sifthen)
{
    sifthen->exp_->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    sifthen->stm_->accept(this); // Body.
    code.at(patchloc) = code.pos() - (patchloc - 1);
}

void CodeGen::visitSIfThenElse(SIfThenElse *sifthenelse)
{
    sifthenelse->exp_->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    sifthenelse->stm_1->accept(this); // Body.
    code.at(patchloc) = code.pos() - (patchloc - 1);
    sifthenelse->stm_2->accept(this); // Body.
}

void CodeGen::visitSFor(SFor *sfor)
{
    sfor->exp_1->accept(this);
    int looploc = code.pos(); // Beginning of test
    sfor->exp_2->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    sfor->stm_->accept(this); // Body.
    sfor->exp_3->accept(this);
    code.add(I_JR);
    code.add(looploc - (code.pos() - 1)); // offset to looploc
    code.at(patchloc) = code.pos() - (patchloc - 1);
}

void CodeGen::visitSForScoped(SForScoped *sfor){
    code.add(I_PROC);
    code.add(1);
    code.add(code.pos() + 1); // function code starts next

    symbols.enter(); // since parameters are local to the function

    code.add(I_CONSTANT);
    code.add(0);

    sfor->type_->accept(this);
    visitIdent(sfor->ident_); // sets currid
    symbols.insert(Symbol(currid, currtype, -1));

    // Compute the address.
    code.add(I_VARIABLE);
    code.add(symbols.levelof(currid));
    code.add(symbols[currid]->address());

    // One copy of the address for the assignment, one for the result.
    code.add_dup();

    // Generate code for the value of the RHS.
    sfor->exp_1->accept(this);

    // Store the value at the computed address.
    code.add(I_ASSIGN);
    code.add(1);

    // Dereference the address and return its value.
    code.add(I_VALUE);

    int looploc = code.pos(); // Beginning of test
    sfor->exp_2->accept(this);
    code.add(I_JR_IF_FALSE);  // Jump past the body.
    code.add(0);
    int patchloc = code.pos() - 1;

    sfor->stm_->accept(this); // Body.
    sfor->exp_3->accept(this);
    code.add(I_JR);
    code.add(looploc - (code.pos() - 1)); // offset to looploc
    code.at(patchloc) = code.pos() - (patchloc - 1);

    symbols.leave(); // since parameters are local to the function
}

void CodeGen::visitSReturn(SReturn *sreturn)
{
    // Store the top of stack (return value) at (bp-funargs)
    code.add(I_VARIABLE);
    code.add(0);
    code.add(-(funargs+1));

    sreturn->exp_->accept(this);

    code.add(I_ASSIGN);
    code.add(1);

    // And return, popping off our parameters.
    code.add(I_ENDPPROC);
    code.add(funargs);
}

void CodeGen::visitEAss(EAss *eass)
{
    visitIdent(eass->ident_); // sets currid
    if (!symbols.exists(currid))
        throw UnknownVar(currid);

    // Compute the address.
    code.add(I_VARIABLE);
    code.add(symbols.levelof(currid));
    code.add(symbols[currid]->address());

    // One copy of the address for the assignment, one for the result.
    code.add_dup();

    // Generate code for the value of the RHS.
    eass->exp_->accept(this);

    // Store the value at the computed address.
    code.add(I_ASSIGN);
    code.add(1);

    // Dereference the address and return its value.
    code.add(I_VALUE);
}

void CodeGen::visitELt(ELt *elt)
{
    elt->exp_1->accept(this);
    elt->exp_2->accept(this);
    code.add(I_LESS);
}

void CodeGen::visitEGt(EGt *egt)
{
    egt->exp_1->accept(this);
    egt->exp_2->accept(this);
    code.add(I_GREATER);
}

void CodeGen::visitEAdd(EAdd *eadd)
{
    eadd->exp_1->accept(this);
    eadd->exp_2->accept(this);
    code.add(I_ADD);
}

void CodeGen::visitESub(ESub *esub)
{
    esub->exp_1->accept(this);
    esub->exp_2->accept(this);
    code.add(I_SUBTRACT);
}

void CodeGen::visitEMul(EMul *emul)
{
    emul->exp_1->accept(this);
    emul->exp_2->accept(this);
    code.add(I_MULTIPLY);
}

void CodeGen::visitCall(Call *call)
{
    visitIdent(call->ident_);
    if (!symbols.exists(currid))
        throw UnknownFunc(currid);

    int level = symbols.levelof(currid);
    Symbol *function_symbol = symbols[currid];
    int addr = function_symbol->address();

    // Make room on the stack for the return value.  Assumes all functions
    // will return some value.
    code.add(I_CONSTANT);
    code.add(0);

    // Generate code for the expressions (which leaves their values on the
    // stack when executed).
    call->listexp_->accept(this);

    function_symbol->check_args(curr_arg_list_types);

    code.add(I_CALL);
    code.add(level);
    code.add(addr);
    
    // The result, if any, is left on the stack.
}

void CodeGen::visitEVar(EVar *evar)
{
    visitIdent(evar->ident_); // sets currid
    if (!symbols.exists(currid))
        throw UnknownVar(currid);

    // Compute the address.
    code.add(I_VARIABLE);
    code.add(symbols.levelof(currid));
    code.add(symbols[currid]->address());
    // Dereference it.
    code.add(I_VALUE);
}

void CodeGen::visitEStr(EStr *estr)
{
    code.add(I_CONSTANT);
    code.add(0); // must be patched for string address
    visitString(estr->string_);
}

void CodeGen::visitEInt(EInt *eint)
{
    visitInteger(eint->integer_);
}

void CodeGen::visitEDouble(EDouble *edouble)
{
    visitDouble(edouble->double_);
}

void CodeGen::visitTInt(TInt *)
{
    currtype = TY_INT;
}

void CodeGen::visitTDouble(TDouble *)
{
    currtype = TY_DOUBLE;
}

void CodeGen::visitListFunction(ListFunction* listfunction)
{
    // Generate code for each function in turn.
    for (ListFunction::iterator i = listfunction->begin() ; i != listfunction->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CodeGen::visitListStm(ListStm* liststm)
{
    // Generate code for each statement in turn.
    for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
    {
        (*i)->accept(this);
    }
}

void CodeGen::visitListDecl(ListDecl* listdecl)
{
    curr_arg_list_types.clear();

    // ListDecl is a function parameter list, so we can compute funargs here.
    funargs = listdecl->size();

    int currarg = 0;
    for (ListDecl::iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
    {
        (*i)->accept(this); // visitDec
        curr_arg_list_types.push_back(currtype);

        // The first argument (currarg = 0) has address -nargs; the last
        // (currarg = nargs - 1) has address -1.
        symbols[currid]->address() = currarg - funargs;
    }
}

void CodeGen::visitListIdent(ListIdent* listident)
{
    // Add all the identifiers to the symbol table.  Assumes currtype is
    // already set.
    for (ListIdent::iterator i = listident->begin(); i != listident->end(); ++i)
    {
        visitIdent(*i); // sets currid

        // First local variable (numvars = funargs) has address 3, etc.
        // If this ListIdent is actually part of a parameter list, these
        // addresses will be fixed up by visitListDecl.
        symbols.insert(Symbol(currid, currtype, 3 + symbols.numvars() - funargs));
    }
}

void CodeGen::visitListExp(ListExp* listexp)
{
    curr_arg_list_types.clear();

    // Evaluate each expression in turn, leaving all the values on the stack.
    for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
    {
        (*i)->accept(this);
        curr_arg_list_types.push_back(currtype);
    }
}


void CodeGen::visitInteger(Integer x)
{
    code.add(I_CONSTANT);
    code.add(x);
}

void CodeGen::visitChar(Char x)
{
    code.add(I_CONSTANT);
    code.add(x);
}

void CodeGen::visitDouble(Double x)
{
    throw Unimplemented("doubles are unimplemented");
}

void CodeGen::visitString(String x)
{
    code.add_string(x, code.pos() - 1);
}

void CodeGen::visitIdent(Ident x)
{
    currid = x;
}


