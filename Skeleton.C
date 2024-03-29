/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitFunction(Function* t) {} //abstract class
void Skeleton::visitDecl(Decl* t) {} //abstract class
void Skeleton::visitFDecl(FDecl* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class

void Skeleton::visitProg(Prog *prog)
{
  /* Code For Prog Goes Here */

  prog->listfunction_->accept(this);

}

void Skeleton::visitGlobal(Global *global)
{
  /* Code For Global Goes Here */

  global->type_->accept(this);
  visitIdent(global->ident_);

}

void Skeleton::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  fun->type_->accept(this);
  visitIdent(fun->ident_);
  fun->listfdecl_->accept(this);
  fun->liststm_->accept(this);

}

void Skeleton::visitDec(Dec *dec)
{
  /* Code For Dec Goes Here */

  dec->type_->accept(this);
  dec->listident_->accept(this);

}

void Skeleton::visitFDec(FDec *fdec)
{
  /* Code For FDec Goes Here */

  fdec->type_->accept(this);
  visitIdent(fdec->ident_);

}

void Skeleton::visitSDecl(SDecl *sdecl)
{
  /* Code For SDecl Goes Here */

  sdecl->decl_->accept(this);

}

void Skeleton::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->exp_->accept(this);

}

void Skeleton::visitSBlock(SBlock *sblock)
{
  /* Code For SBlock Goes Here */

  sblock->liststm_->accept(this);

}

void Skeleton::visitSWhile(SWhile *swhile)
{
  /* Code For SWhile Goes Here */

  swhile->exp_->accept(this);
  swhile->stm_->accept(this);

}

void Skeleton::visitSRepeat(SRepeat *srepeat)
{
  /* Code For SRepeat Goes Here */

  srepeat->stm_->accept(this);
  srepeat->exp_->accept(this);

}

void Skeleton::visitSIf(SIf *sif)
{
  /* Code For SIf Goes Here */

  sif->exp_->accept(this);
  sif->stm_->accept(this);

}

void Skeleton::visitSIfThenElse(SIfThenElse *sifthenelse)
{
  /* Code For SIfThenElse Goes Here */

  sifthenelse->exp_->accept(this);
  sifthenelse->stm_1->accept(this);
  sifthenelse->stm_2->accept(this);

}

void Skeleton::visitSIfThen(SIfThen *sifthen)
{
  /* Code For SIfThen Goes Here */

  sifthen->exp_->accept(this);
  sifthen->stm_->accept(this);

}

void Skeleton::visitSFor(SFor *sfor)
{
  /* Code For SFor Goes Here */

  sfor->exp_1->accept(this);
  sfor->exp_2->accept(this);
  sfor->stm_->accept(this);

}

void Skeleton::visitSForScoped(SForScoped *sforscoped)
{
  /* Code For SForScoped Goes Here */

  sforscoped->type_->accept(this);
  visitIdent(sforscoped->ident_);
  sforscoped->exp_1->accept(this);
  sforscoped->exp_2->accept(this);
  sforscoped->exp_3->accept(this);
  sforscoped->stm_->accept(this);

}

void Skeleton::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */

  sreturn->exp_->accept(this);

}

void Skeleton::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */

  visitIdent(eass->ident_);
  eass->exp_->accept(this);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

}

void Skeleton::visitEAdd(EAdd *eadd)
{
  /* Code For EAdd Goes Here */

  eadd->exp_1->accept(this);
  eadd->exp_2->accept(this);

}

void Skeleton::visitESub(ESub *esub)
{
  /* Code For ESub Goes Here */

  esub->exp_1->accept(this);
  esub->exp_2->accept(this);

}

void Skeleton::visitEMul(EMul *emul)
{
  /* Code For EMul Goes Here */

  emul->exp_1->accept(this);
  emul->exp_2->accept(this);

}

void Skeleton::visitCall(Call *call)
{
  /* Code For Call Goes Here */

  visitIdent(call->ident_);
  call->listexp_->accept(this);

}

void Skeleton::visitEVar(EVar *evar)
{
  /* Code For EVar Goes Here */

  visitIdent(evar->ident_);

}

void Skeleton::visitEStr(EStr *estr)
{
  /* Code For EStr Goes Here */

  visitString(estr->string_);

}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);

}

void Skeleton::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */

  visitDouble(edouble->double_);

}

void Skeleton::visitTInt(TInt *tint)
{
  /* Code For TInt Goes Here */


}

void Skeleton::visitTDouble(TDouble *tdouble)
{
  /* Code For TDouble Goes Here */


}


void Skeleton::visitListFunction(ListFunction* listfunction)
{
  for (ListFunction::iterator i = listfunction->begin() ; i != listfunction->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListFDecl(ListFDecl* listfdecl)
{
  for (ListFDecl::iterator i = listfdecl->begin() ; i != listfdecl->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListIdent(ListIdent* listident)
{
  for (ListIdent::iterator i = listident->begin() ; i != listident->end() ; ++i)
  {
    visitIdent(*i) ;
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



