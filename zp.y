/* This Bison file was machine-generated by BNFC */
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n", 
    yy_mylinenumber, str, yytext);
}



static Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}
Program* pProgram(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

static Function* YY_RESULT_Function_ = 0;
Function* pFunction(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Function_;
  }
}
Function* pFunction(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Function_;
  }
}

static Decl* YY_RESULT_Decl_ = 0;
Decl* pDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}
Decl* pDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}

static FDecl* YY_RESULT_FDecl_ = 0;
FDecl* pFDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FDecl_;
  }
}
FDecl* pFDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_FDecl_;
  }
}

static ListFunction* YY_RESULT_ListFunction_ = 0;
ListFunction* pListFunction(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunction_;
  }
}
ListFunction* pListFunction(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunction_;
  }
}

static ListStm* YY_RESULT_ListStm_ = 0;
ListStm* pListStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}
ListStm* pListStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStm_;
  }
}

static ListFDecl* YY_RESULT_ListFDecl_ = 0;
ListFDecl* pListFDecl(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFDecl_;
  }
}
ListFDecl* pListFDecl(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFDecl_;
  }
}

static ListIdent* YY_RESULT_ListIdent_ = 0;
ListIdent* pListIdent(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListIdent_;
  }
}
ListIdent* pListIdent(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListIdent_;
  }
}

static Stm* YY_RESULT_Stm_ = 0;
Stm* pStm(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}
Stm* pStm(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Stm_;
  }
}

static Exp* YY_RESULT_Exp_ = 0;
Exp* pExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}
Exp* pExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

static ListExp* YY_RESULT_ListExp_ = 0;
ListExp* pListExp(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}
ListExp* pListExp(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}

static Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}
Type* pType(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}



%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  Function* function_;
  Decl* decl_;
  FDecl* fdecl_;
  ListFunction* listfunction_;
  ListStm* liststm_;
  ListFDecl* listfdecl_;
  ListIdent* listident_;
  Stm* stm_;
  Exp* exp_;
  ListExp* listexp_;
  Type* type_;
}

%token _ERROR_
%token _SYMB_0    //   ;
%token _SYMB_1    //   (
%token _SYMB_2    //   )
%token _SYMB_3    //   {
%token _SYMB_4    //   }
%token _SYMB_5    //   ,
%token _SYMB_6    //   =
%token _SYMB_7    //   <
%token _SYMB_8    //   >
%token _SYMB_9    //   +
%token _SYMB_10    //   -
%token _SYMB_11    //   *
%token _SYMB_12    //   double
%token _SYMB_13    //   else
%token _SYMB_14    //   for
%token _SYMB_15    //   if
%token _SYMB_16    //   int
%token _SYMB_17    //   repeat
%token _SYMB_18    //   return
%token _SYMB_19    //   then
%token _SYMB_20    //   until
%token _SYMB_21    //   while

%type <program_> Program
%type <function_> Function
%type <decl_> Decl
%type <fdecl_> FDecl
%type <listfunction_> ListFunction
%type <liststm_> ListStm
%type <listfdecl_> ListFDecl
%type <listident_> ListIdent
%type <stm_> Stm
%type <exp_> Exp
%type <exp_> Exp1
%type <exp_> Exp2
%type <exp_> Exp3
%type <exp_> Exp4
%type <listexp_> ListExp
%type <type_> Type

%start Program
%token<string_> _STRING_
%token<int_> _INTEGER_
%token<double_> _DOUBLE_
%token<string_> _IDENT_

%%
Program : ListFunction {  $$ = new Prog($1); YY_RESULT_Program_= $$; } 
;
Function : Type _IDENT_ _SYMB_0 {  $$ = new Global($1, $2); YY_RESULT_Function_= $$; } 
  | Type _IDENT_ _SYMB_1 ListFDecl _SYMB_2 _SYMB_3 ListStm _SYMB_4 {  std::reverse($4->begin(),$4->end()) ;$$ = new Fun($1, $2, $4, $7); YY_RESULT_Function_= $$; }
;
Decl : Type ListIdent {  std::reverse($2->begin(),$2->end()) ;$$ = new Dec($1, $2); YY_RESULT_Decl_= $$; } 
;
FDecl : Type _IDENT_ {  $$ = new FDec($1, $2); YY_RESULT_FDecl_= $$; } 
;
ListFunction : /* empty */ {  $$ = new ListFunction(); YY_RESULT_ListFunction_= $$; } 
  | ListFunction Function {  $1->push_back($2) ; $$ = $1 ; YY_RESULT_ListFunction_= $$; }
;
ListStm : /* empty */ {  $$ = new ListStm(); YY_RESULT_ListStm_= $$; } 
  | ListStm Stm {  $1->push_back($2) ; $$ = $1 ; YY_RESULT_ListStm_= $$; }
;
ListFDecl : /* empty */ {  $$ = new ListFDecl(); YY_RESULT_ListFDecl_= $$; } 
  | FDecl {  $$ = new ListFDecl() ; $$->push_back($1); YY_RESULT_ListFDecl_= $$; }
  | FDecl _SYMB_5 ListFDecl {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListFDecl_= $$; }
;
ListIdent : _IDENT_ {  $$ = new ListIdent() ; $$->push_back($1); YY_RESULT_ListIdent_= $$; } 
  | _IDENT_ _SYMB_5 ListIdent {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListIdent_= $$; }
;
Stm : Decl _SYMB_0 {  $$ = new SDecl($1); YY_RESULT_Stm_= $$; } 
  | Exp _SYMB_0 {  $$ = new SExp($1); YY_RESULT_Stm_= $$; }
  | _SYMB_3 ListStm _SYMB_4 {  $$ = new SBlock($2); YY_RESULT_Stm_= $$; }
  | _SYMB_21 _SYMB_1 Exp _SYMB_2 Stm {  $$ = new SWhile($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_17 Stm _SYMB_20 _SYMB_1 Exp _SYMB_2 _SYMB_0 {  $$ = new SRepeat($2, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_15 _SYMB_1 Exp _SYMB_2 Stm {  $$ = new SIf($3, $5); YY_RESULT_Stm_= $$; }
  | _SYMB_15 _SYMB_1 Exp _SYMB_2 _SYMB_19 Stm _SYMB_13 Stm {  $$ = new SIfThenElse($3, $6, $8); YY_RESULT_Stm_= $$; }
  | _SYMB_15 _SYMB_1 Exp _SYMB_2 _SYMB_19 Stm {  $$ = new SIfThen($3, $6); YY_RESULT_Stm_= $$; }
  | _SYMB_14 _SYMB_1 Exp _SYMB_0 Exp _SYMB_0 Exp _SYMB_2 Stm {  $$ = new SFor($3, $5, $7, $9); YY_RESULT_Stm_= $$; }
  | _SYMB_14 _SYMB_1 Type _IDENT_ _SYMB_6 Exp _SYMB_0 Exp _SYMB_0 Exp _SYMB_2 Stm {  $$ = new SForScoped($3, $4, $6, $8, $10, $12); YY_RESULT_Stm_= $$; }
  | _SYMB_18 Exp _SYMB_0 {  $$ = new SReturn($2); YY_RESULT_Stm_= $$; }
;
Exp : _IDENT_ _SYMB_6 Exp {  $$ = new EAss($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp1 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp1 : Exp2 _SYMB_7 Exp2 {  $$ = new ELt($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp2 _SYMB_8 Exp2 {  $$ = new EGt($1, $3); YY_RESULT_Exp_= $$; }
  | Exp2 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp2 : Exp2 _SYMB_9 Exp3 {  $$ = new EAdd($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp2 _SYMB_10 Exp3 {  $$ = new ESub($1, $3); YY_RESULT_Exp_= $$; }
  | Exp3 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp3 : Exp3 _SYMB_11 Exp4 {  $$ = new EMul($1, $3); YY_RESULT_Exp_= $$; } 
  | Exp4 {  $$ = $1; YY_RESULT_Exp_= $$; }
;
Exp4 : _IDENT_ _SYMB_1 ListExp _SYMB_2 {  std::reverse($3->begin(),$3->end()) ;$$ = new Call($1, $3); YY_RESULT_Exp_= $$; } 
  | _IDENT_ {  $$ = new EVar($1); YY_RESULT_Exp_= $$; }
  | _STRING_ {  $$ = new EStr($1); YY_RESULT_Exp_= $$; }
  | _INTEGER_ {  $$ = new EInt($1); YY_RESULT_Exp_= $$; }
  | _DOUBLE_ {  $$ = new EDouble($1); YY_RESULT_Exp_= $$; }
  | _SYMB_1 Exp _SYMB_2 {  $$ = $2; YY_RESULT_Exp_= $$; }
;
ListExp : /* empty */ {  $$ = new ListExp(); YY_RESULT_ListExp_= $$; } 
  | Exp {  $$ = new ListExp() ; $$->push_back($1); YY_RESULT_ListExp_= $$; }
  | Exp _SYMB_5 ListExp {  $3->push_back($1) ; $$ = $3 ; YY_RESULT_ListExp_= $$; }
;
Type : _SYMB_16 {  $$ = new TInt(); YY_RESULT_Type_= $$; } 
  | _SYMB_12 {  $$ = new TDouble(); YY_RESULT_Type_= $$; }
;

