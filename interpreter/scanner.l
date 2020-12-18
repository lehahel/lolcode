%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "driver.hh"
    #include "parser.hh"
    #include "lolobject.h"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_OBJECT(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   -?[0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
    // A handy shortcut to the location held by the driver.
    yy::location& loc = driver.location;
    // Code run each time yylex is called.
    loc.step();
%}

{blank}+        loc.step ();
\n+             loc.lines (yyleng); loc.step ();

"HAI"           return yy::parser::make_BEGIN  (loc);
"KTHXBYE"       return yy::parser::make_ENDING  (loc);

"I HAS A"       return yy::parser::make_DEFINE (loc);
"R"             return yy::parser::make_ASSIGN (loc);
"SUM OF"        return yy::parser::make_PLUS   (loc);
"DIFF OF"       return yy::parser::make_MINUS  (loc);
"PRODUKT OF"    return yy::parser::make_STAR   (loc);
"QUOSHUNT OF"   return yy::parser::make_SLASH  (loc);

"BOTH SAEM"     return yy::parser::make_AND    (loc);
"EITHER OF"     return yy::parser::make_OR     (loc);

"O RLY?"        return yy::parser::make_IF     (loc);
"YA RLY"        return yy::parser::make_DO     (loc);
"NO WAI"        return yy::parser::make_ELSE   (loc);
"OIC"           return yy::parser::make_ENDIF  (loc);

"IM IN YR"      return yy::parser::make_LOOP   (loc);
"YR"            return yy::parser::make_YR     (loc);
"TIL"           return yy::parser::make_TILL   (loc);
"WILE"          return yy::parser::make_WHILE  (loc);

"("             return yy::parser::make_LPAREN (loc);
")"             return yy::parser::make_RPAREN (loc);

BTW.*\n         ; // comment

{int}           return make_OBJECT(yytext, loc);
{id}            return yy::parser::make_OBJECT(LolObject(yytext), loc);

.               {}; //throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext)); }

<<EOF>>         return yy::parser::make_END     (loc);
%%

yy::parser::symbol_type make_OBJECT(const std::string &s,
                                    const yy::parser::location_type& loc) {
    errno = 0;
    long long n = strtol(s.c_str(), NULL, 10);
    if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE)) {
        //throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
    }
    return yy::parser::make_OBJECT(LolObject((int) n), loc);
}