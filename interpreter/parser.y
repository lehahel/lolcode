%skeleton "lalr1.cc"
%require "3.4"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include "lolobject.h"
    #include "lexems.h"
    #include "loldriver.h"
    #include <string>
    class Scanner;
    class CDriver;
}

// %param { Scanner &scn }
// %param { Driver  &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "lexems.h"
    #include "loldriver.h"
    #include "driver.hh"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, CDriver& driver) {
        return scanner.ScanToken();
    }
    CVariablesManager globals;
}

%lex-param   { Scanner &scanner }
%lex-param   { CDriver &driver  }
%parse-param { Scanner &scanner }
%parse-param { CDriver &driver  }

%locations

%define api.token.prefix {TOK_}

%token
    END 0   "end of file"
    ENDING  "KTHBYE"
    BEGIN   "HAI"
    ASSIGN  "R"
    DEFINE  "I HAS A"
    PLUS    "SUM OF"
    MINUS   "DIFF OF"
    STAR    "PRODUKT OF"
    SLASH   "QUOSHUNT OF"
    MOD     "MOD OF"
    AND     "BOTH SAEM"
    OR      "EITHER OF"
    LPAREN  "("
    RPAREN  ")"
    YR      "YR"
    LOOP    "IM IN YR"
    TILL    "TILL"
    WHILE   "WILE"
    IF      "O RLY?"
    DO      "YA RLY"
    ELSE    "NO WAI"
    INC     "UPPIN"
    DEC     "NERFIN"
    ENDIF   "OIK"
;

%token <std::string> IDENTIFIER "identifier"
%token <int>         NUMBER
%token <double>      DOUBLE
%token <std::string> STRING
%token <const char*> CSTRING
%token <bool>        BOOL
%token /*         */ EOL

%nterm <LolObject> object
%nterm <CExpression *> exp
%nterm <CExpression *> factor
%nterm <CExpression *> term

%printer { yyo << $$; } <*>;

%%
%start program;

object:
    NUMBER     { $$ = LolObject($1); }
  | DOUBLE     { $$ = LolObject($1); }
  | STRING     { $$ = LolObject($1); }
  | CSTRING    { $$ = LolObject($1); }
  | BOOL       { $$ = LolObject($1); }
  ;

program: BEGIN codeblock ENDING {};


exp: factor
 | PLUS    exp      exp     { $$ = new CExpression(ExprType::ADD, $2, $3, globals); }
 | MINUS   exp      factor  { $$ = new CExpression(ExprType::SUB, $2, $3, globals); }
 ;


codeblock: 
   %empty                   {            }
 | codeblock exp            {/*driver.add_block(yylineno, $2);*/}
 | codeblock if_flow        { /* TODO */ }
 | codeblock while_flow     { /* TODO */ }
 | codeblock till_flow      { /* TODO */ }
 ;


factor:    
   term                     { $$ = $1; }
 | STAR    factor   term    { $$ = new CExpression(ExprType::MUL, $2, $3, globals); }
 | SLASH   factor   term    { $$ = new CExpression(ExprType::DIV, $2, $3, globals); }
 | MOD     factor   term    { $$ = new CExpression(ExprType::MOD, $2, $3, globals); }
 | AND     factor   term    { $$ = new CExpression(ExprType::AND, $2, $3, globals); }
 | OR      factor   term    { $$ = new CExpression(ExprType::OR , $2, $3, globals); }
 ;


term: 
   object                   { $$ = new CExpression($1, globals); }
 | LPAREN  exp      RPAREN  { $$ = $2; }
 ;


assignment:
DEFINE "identifier" exp {
    driver.manager().set_var($2, $3);
}
  | "identifier" ASSIGN exp {
    driver.manager().set_var($1, $3);
};


if_flow:
exp IF DO codeblock ELSE codeblock ENDIF {
    // pass
};


while_flow:
LOOP "identifier" INC YR "identifier" WHILE exp {}
  | LOOP "identifier" DEC YR "identifier" WHILE exp {
    // pass
};


till_flow:  LOOP "identifier" INC  YR "identifier" TILL exp {}
           | LOOP "identifier" DEC YR "idenrifier" TILL exp {
    // pass;
 };

%left "+" "-";
%left "*" "/";

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
