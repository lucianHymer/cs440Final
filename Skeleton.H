#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"


class Skeleton : public Visitor
{
public:
  void visitProgram(Program* p);
  void visitFunction(Function* p);
  void visitDecl(Decl* p);
  void visitFDecl(FDecl* p);
  void visitStm(Stm* p);
  void visitExp(Exp* p);
  void visitType(Type* p);
  void visitProg(Prog* p);
  void visitGlobal(Global* p);
  void visitFun(Fun* p);
  void visitDec(Dec* p);
  void visitFDec(FDec* p);
  void visitSDecl(SDecl* p);
  void visitSExp(SExp* p);
  void visitSBlock(SBlock* p);
  void visitSWhile(SWhile* p);
  void visitSRepeat(SRepeat* p);
  void visitSIf(SIf* p);
  void visitSIfThenElse(SIfThenElse* p);
  void visitSIfThen(SIfThen* p);
  void visitSFor(SFor* p);
  void visitSForScoped(SForScoped* p);
  void visitSReturn(SReturn* p);
  void visitEAss(EAss* p);
  void visitELt(ELt* p);
  void visitEGt(EGt* p);
  void visitEAdd(EAdd* p);
  void visitESub(ESub* p);
  void visitEMul(EMul* p);
  void visitCall(Call* p);
  void visitEVar(EVar* p);
  void visitEStr(EStr* p);
  void visitEInt(EInt* p);
  void visitEDouble(EDouble* p);
  void visitTInt(TInt* p);
  void visitTDouble(TDouble* p);
  void visitListFunction(ListFunction* p);
  void visitListStm(ListStm* p);
  void visitListFDecl(ListFDecl* p);
  void visitListIdent(ListIdent* p);
  void visitListExp(ListExp* p);

  void visit"Integer"("Integer" x);
  void visit"Char"("Char" x);
  void visit"Double"("Double" x);
  void visit"String"("String" x);
  void visit"Ident"("Ident" x);

};


#endif
