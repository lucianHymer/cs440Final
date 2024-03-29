#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class Program;
class Function;
class Decl;
class FDecl;
class ListFunction;
class ListStm;
class ListFDecl;
class ListIdent;
class Stm;
class Exp;
class ListExp;
class Type;

typedef union
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
} YYSTYPE;

Program* pProgram(FILE *inp);
Program* pProgram(const char *str);
Function* pFunction(FILE *inp);
Function* pFunction(const char *str);
Decl* pDecl(FILE *inp);
Decl* pDecl(const char *str);
FDecl* pFDecl(FILE *inp);
FDecl* pFDecl(const char *str);
ListFunction* pListFunction(FILE *inp);
ListFunction* pListFunction(const char *str);
ListStm* pListStm(FILE *inp);
ListStm* pListStm(const char *str);
ListFDecl* pListFDecl(FILE *inp);
ListFDecl* pListFDecl(const char *str);
ListIdent* pListIdent(FILE *inp);
ListIdent* pListIdent(const char *str);
Stm* pStm(FILE *inp);
Stm* pStm(const char *str);
Exp* pExp(FILE *inp);
Exp* pExp(const char *str);
ListExp* pListExp(FILE *inp);
ListExp* pListExp(const char *str);
Type* pType(FILE *inp);
Type* pType(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _STRING_ 281
#define _INTEGER_ 282
#define _DOUBLE_ 283
#define _IDENT_ 284

extern YYSTYPE yylval;

#endif
