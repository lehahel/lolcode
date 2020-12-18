%skeleton "lalr1.cc"
%require "3.4"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include "lolobject.h"
    #include <string>
    class Scanner;
    class Driver;
}

// %param { Scanner &scn }
// %param { Driver  &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param   { Scanner &scanner }
%lex-param   { Driver  &driver  }
%parse-param { Scanner &scanner }
%parse-param { Driver  &driver  }

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
    ENDIF   "OIK"
;

%token <std::string> IDENTIFIER "identifier"
%token <LolObject> OBJECT "object"
%token EOL

%nterm <LolObject> exp
%nterm <LolObject> factor
%nterm <LolObject> term

%printer { yyo << $$; } <*>;

%%
%start unit;

program: BEGIN codeblock ENDING {};

unit: assignments exp { driver.result = $2; };

exp: factor
 | PLUS    exp      exp     { $$ = $2 + $3; }
 | MINUS   exp      factor  { $$ = $2 - $3; }
 ;

codeblock: exp 
 | if_flow
 | while_flow 
 | till_flow 
 | assignments
 | codeblock codeblock


factor:    term
 | STAR    factor   term    { $$ = $2 * $3; }
 | SLASH   factor   term    { $$ = $2 / $3; }
 | AND     factor   term    { $$ = $2 & $3; }
 | OR      factor   term    { $$ = $2 | $3; };


term: OBJECT
 | LPAREN  exp      RPAREN  { $$ = $2; };


assignments: %empty {}
 | assignments assignment {};


assignment:
    DEFINE   "identifier" exp {
        driver.variables[$2] = $3;
        // std::cout << drv.location.begin.line << "-" << drv.location.end.line << std::endl;
    }
    | "identifier" ASSIGN exp {
        driver.variables[$1] = $3;
    };

if_flow: exp IF DO codeblock ELSE codeblock ENDIF {
    // if ($1) {
    //     $4;
    // } else {
    //     $6;
    // }
};
 
 while_flow: LOOP "identifier" YR "identifier" WHILE exp {
    // pass
 };
 
 till_flow:  LOOP "identifier" YR "identifier" TILL  exp {
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
