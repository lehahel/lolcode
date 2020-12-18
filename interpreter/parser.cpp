// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 24 "parser.y"

    #include "lexems.h"
    #include "loldriver.h"
    #include "driver.hh"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, CDriver& driver) {
        return scanner.ScanToken();
    }
    CVariablesManager globals;

#line 57 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 151 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, CDriver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 40: // exp
      case 41: // factor
      case 42: // term
        value.YY_MOVE_OR_COPY< CExpression * > (YY_MOVE (that.value));
        break;

      case 39: // object
        value.YY_MOVE_OR_COPY< LolObject > (YY_MOVE (that.value));
        break;

      case 31: // BOOL
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 30: // CSTRING
        value.YY_MOVE_OR_COPY< const char* > (YY_MOVE (that.value));
        break;

      case 28: // DOUBLE
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 27: // NUMBER
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 26: // "identifier"
      case 29: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 40: // exp
      case 41: // factor
      case 42: // term
        value.move< CExpression * > (YY_MOVE (that.value));
        break;

      case 39: // object
        value.move< LolObject > (YY_MOVE (that.value));
        break;

      case 31: // BOOL
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 30: // CSTRING
        value.move< const char* > (YY_MOVE (that.value));
        break;

      case 28: // DOUBLE
        value.move< double > (YY_MOVE (that.value));
        break;

      case 27: // NUMBER
        value.move< int > (YY_MOVE (that.value));
        break;

      case 26: // "identifier"
      case 29: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 40: // exp
      case 41: // factor
      case 42: // term
        value.move< CExpression * > (that.value);
        break;

      case 39: // object
        value.move< LolObject > (that.value);
        break;

      case 31: // BOOL
        value.move< bool > (that.value);
        break;

      case 30: // CSTRING
        value.move< const char* > (that.value);
        break;

      case 28: // DOUBLE
        value.move< double > (that.value);
        break;

      case 27: // NUMBER
        value.move< int > (that.value);
        break;

      case 26: // "identifier"
      case 29: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 26: // "identifier"
#line 85 "parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 426 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 27: // NUMBER
#line 85 "parser.y"
        { yyo << yysym.value.template as < int > (); }
#line 432 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 28: // DOUBLE
#line 85 "parser.y"
        { yyo << yysym.value.template as < double > (); }
#line 438 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 29: // STRING
#line 85 "parser.y"
        { yyo << yysym.value.template as < std::string > (); }
#line 444 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 30: // CSTRING
#line 85 "parser.y"
        { yyo << yysym.value.template as < const char* > (); }
#line 450 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 31: // BOOL
#line 85 "parser.y"
        { yyo << yysym.value.template as < bool > (); }
#line 456 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 39: // object
#line 85 "parser.y"
        { yyo << yysym.value.template as < LolObject > (); }
#line 462 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 40: // exp
#line 85 "parser.y"
        { yyo << yysym.value.template as < CExpression * > (); }
#line 468 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 41: // factor
#line 85 "parser.y"
        { yyo << yysym.value.template as < CExpression * > (); }
#line 474 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      case 42: // term
#line 85 "parser.y"
        { yyo << yysym.value.template as < CExpression * > (); }
#line 480 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 40: // exp
      case 41: // factor
      case 42: // term
        yylhs.value.emplace< CExpression * > ();
        break;

      case 39: // object
        yylhs.value.emplace< LolObject > ();
        break;

      case 31: // BOOL
        yylhs.value.emplace< bool > ();
        break;

      case 30: // CSTRING
        yylhs.value.emplace< const char* > ();
        break;

      case 28: // DOUBLE
        yylhs.value.emplace< double > ();
        break;

      case 27: // NUMBER
        yylhs.value.emplace< int > ();
        break;

      case 26: // "identifier"
      case 29: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 91 "parser.y"
    { yylhs.value.as < LolObject > () = LolObject(yystack_[0].value.as < int > ()); }
#line 751 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 3:
#line 92 "parser.y"
    { yylhs.value.as < LolObject > () = LolObject(yystack_[0].value.as < double > ()); }
#line 757 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 4:
#line 93 "parser.y"
    { yylhs.value.as < LolObject > () = LolObject(yystack_[0].value.as < std::string > ()); }
#line 763 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 5:
#line 94 "parser.y"
    { yylhs.value.as < LolObject > () = LolObject(yystack_[0].value.as < const char* > ()); }
#line 769 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 6:
#line 95 "parser.y"
    { yylhs.value.as < LolObject > () = LolObject(yystack_[0].value.as < bool > ()); }
#line 775 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 7:
#line 98 "parser.y"
    {}
#line 781 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 8:
#line 101 "parser.y"
    { yylhs.value.as < CExpression * > () = yystack_[0].value.as < CExpression * > (); }
#line 787 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 9:
#line 102 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::ADD, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 793 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 10:
#line 103 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::SUB, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 799 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 11:
#line 108 "parser.y"
    {            }
#line 805 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 12:
#line 109 "parser.y"
    {/*driver.add_block(yylineno, $2);*/}
#line 811 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 13:
#line 110 "parser.y"
    { /* TODO */ }
#line 817 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 14:
#line 111 "parser.y"
    { /* TODO */ }
#line 823 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 15:
#line 112 "parser.y"
    { /* TODO */ }
#line 829 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 16:
#line 117 "parser.y"
    { yylhs.value.as < CExpression * > () = yystack_[0].value.as < CExpression * > (); }
#line 835 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 17:
#line 118 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::MUL, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 841 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 18:
#line 119 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::DIV, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 847 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 19:
#line 120 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::MOD, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 853 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 20:
#line 121 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::AND, yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 859 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 21:
#line 122 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(ExprType::OR , yystack_[1].value.as < CExpression * > (), yystack_[0].value.as < CExpression * > (), globals); }
#line 865 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 22:
#line 127 "parser.y"
    { yylhs.value.as < CExpression * > () = new CExpression(yystack_[0].value.as < LolObject > (), globals); }
#line 871 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 23:
#line 128 "parser.y"
    { yylhs.value.as < CExpression * > () = yystack_[1].value.as < CExpression * > (); }
#line 877 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 24:
#line 142 "parser.y"
    {
    // pass
}
#line 885 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 25:
#line 148 "parser.y"
    {}
#line 891 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 26:
#line 149 "parser.y"
    {
    // pass
}
#line 899 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 27:
#line 154 "parser.y"
    {}
#line 905 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;

  case 28:
#line 155 "parser.y"
    {
    // pass;
 }
#line 913 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"
    break;


#line 917 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -28;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      12,   -28,    17,     1,   -28,   -28,    76,    76,    82,    82,
      82,    82,    82,    76,    -7,   -28,   -28,   -28,   -28,   -28,
     -28,    21,   -28,   -28,   -28,   -28,   -28,    76,    82,    87,
      87,    87,    87,    87,    29,   -21,    24,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,    30,    31,   -28,    41,    40,
      26,   -13,    50,    52,   -28,    76,    76,    76,    76,    51,
     -28,   -28,   -28,   -28,   -28
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    11,     0,     0,     1,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
      22,    12,     8,    16,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,    17,
      18,    19,    20,    21,    23,     0,     0,    11,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      27,    25,    26,    28,    24
  };

  const signed char
  parser::yypgoto_[] =
  {
     -28,   -28,    -6,    14,    90,   -28,   -27,   -28,   -28,   -28
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    20,    21,    22,    23,     2,     3,    24,    25,    26
  };

  const unsigned char
  parser::yytable_[] =
  {
      27,    28,    45,    46,     5,    55,    56,    34,     6,     7,
       8,     9,    10,    11,    12,    13,     1,     4,    14,    35,
      50,    37,    29,    30,    31,    32,    33,    59,    15,    16,
      17,    18,    19,     6,     7,     8,     9,    10,    11,    12,
      13,    36,    38,    14,    44,    47,    48,    49,    54,    60,
      61,    62,    63,    15,    16,    17,    18,    19,     6,     7,
       8,     9,    10,    11,    12,    13,    52,    51,    14,    57,
      58,     0,     0,    53,     0,     0,    64,     0,    15,    16,
      17,    18,    19,     6,     7,     8,     9,    10,    11,    12,
      13,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,    13,     0,    15,    16,    17,    18,    19,     0,    15,
      16,    17,    18,    19,    15,    16,    17,    18,    19,    39,
      40,    41,    42,    43
  };

  const signed char
  parser::yycheck_[] =
  {
       6,     7,    23,    24,     3,    18,    19,    13,     7,     8,
       9,    10,    11,    12,    13,    14,     4,     0,    17,    26,
      47,    27,     8,     9,    10,    11,    12,    54,    27,    28,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,    20,    28,    17,    15,    21,    16,    16,    22,    55,
      56,    57,    58,    27,    28,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    26,    26,    17,    19,
      18,    -1,    -1,    33,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    13,
      14,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    14,    -1,    27,    28,    29,    30,    31,    -1,    27,
      28,    29,    30,    31,    27,    28,    29,    30,    31,    29,
      30,    31,    32,    33
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     4,    43,    44,     0,     3,     7,     8,     9,    10,
      11,    12,    13,    14,    17,    27,    28,    29,    30,    31,
      39,    40,    41,    42,    45,    46,    47,    40,    40,    41,
      41,    41,    41,    41,    40,    26,    20,    40,    41,    42,
      42,    42,    42,    42,    15,    23,    24,    21,    16,    16,
      44,    26,    26,    33,    22,    18,    19,    19,    18,    44,
      40,    40,    40,    40,    25
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    38,    39,    39,    39,    39,    39,    43,    40,    40,
      40,    44,    44,    44,    44,    44,    41,    41,    41,    41,
      41,    41,    42,    42,    45,    46,    46,    47,    47
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     0,     2,     2,     2,     2,     1,     3,     3,     3,
       3,     3,     1,     3,     7,     7,     7,     7,     7
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"KTHBYE\"", "\"HAI\"",
  "\"R\"", "\"I HAS A\"", "\"SUM OF\"", "\"DIFF OF\"", "\"PRODUKT OF\"",
  "\"QUOSHUNT OF\"", "\"MOD OF\"", "\"BOTH SAEM\"", "\"EITHER OF\"",
  "\"(\"", "\")\"", "\"YR\"", "\"IM IN YR\"", "\"TILL\"", "\"WILE\"",
  "\"O RLY?\"", "\"YA RLY\"", "\"NO WAI\"", "\"UPPIN\"", "\"NERFIN\"",
  "\"OIK\"", "\"identifier\"", "NUMBER", "DOUBLE", "STRING", "CSTRING",
  "BOOL", "EOL", "\"idenrifier\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "$accept", "object", "exp", "factor", "term", "program", "codeblock",
  "if_flow", "while_flow", "till_flow", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    91,    91,    92,    93,    94,    95,    98,   101,   102,
     103,   108,   109,   110,   111,   112,   117,   118,   119,   120,
     121,   122,   127,   128,   142,   148,   149,   154,   155
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1350 "/home/lehahel/formal_prac/repo/lolcode/interpreter/parser.cpp"

#line 162 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
