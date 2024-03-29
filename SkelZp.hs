module SkelZp where

-- Haskell module generated by the BNF converter

import AbsZp
import ErrM
type Result = Err String

failure :: Show a => a -> Result
failure x = Bad $ "Undefined case: " ++ show x

transIdent :: Ident -> Result
transIdent x = case x of
  Ident string -> failure x
transProgram :: Program -> Result
transProgram x = case x of
  Prog functions -> failure x
transFunction :: Function -> Result
transFunction x = case x of
  Fun type_ ident decls stms -> failure x
transDecl :: Decl -> Result
transDecl x = case x of
  Dec type_ idents -> failure x
transStm :: Stm -> Result
transStm x = case x of
  SDecl decl -> failure x
  SExp exp -> failure x
  SBlock stms -> failure x
  SWhile exp stm -> failure x
  SRepeat stm exp -> failure x
  SIf exp stm -> failure x
  SIfThenElse exp stm1 stm2 -> failure x
  SIfThen exp stm -> failure x
  SFor exp1 exp2 exp3 stm -> failure x
  SReturn exp -> failure x
transExp :: Exp -> Result
transExp x = case x of
  EAss ident exp -> failure x
  ELt exp1 exp2 -> failure x
  EGt exp1 exp2 -> failure x
  EAdd exp1 exp2 -> failure x
  ESub exp1 exp2 -> failure x
  EMul exp1 exp2 -> failure x
  Call ident exps -> failure x
  EVar ident -> failure x
  EStr string -> failure x
  EInt integer -> failure x
  EDouble double -> failure x
transType :: Type -> Result
transType x = case x of
  TInt -> failure x
  TDouble -> failure x

