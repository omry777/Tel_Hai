
/*  A Bison parser, made from lps.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ID	258
#define	NUM	259
#define	RELOP	260
#define	LOGOP	261
#define	ADDOP	262
#define	MULOP	263
#define	ASSIGNOP	264
#define	WS	265
#define	SEP	266
#define	RES	267
#define	PROG	268
#define	START	269
#define	VAR	270
#define	DO	271
#define	ELSE	272
#define	IF	273
#define	ENDI	274
#define	INT	275
#define	PUT	276
#define	GET	277
#define	REAL	278
#define	THEN	279
#define	LOOP	280
#define	ENDL	281
#define	UNTIL	282
#define	ENDP	283

#line 1 "lps.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineCnt = 1;
extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;

int yylex();
void yyerror(char *err);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		109
#define	YYFLAG		-32768
#define	YYNTBASE	36

#define YYTRANSLATE(x) ((unsigned)(x) <= 283 ? yytranslate[x] : 52)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
    33,     2,     2,    31,     2,    29,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    30,    34,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,    12,    22,    29,    31,    34,    38,    41,    44,    47,
    50,    52,    61,    71,    73,    78,    88,    93,    97,   102,
   104,   106,   107,   111,   113,   115,   119,   123,   127,   131,
   134,   140,   142,   144,   146,   147,   152,   155
};

static const short yyrhs[] = {    13,
    49,     3,    50,    15,    37,    14,    51,    38,    28,    29,
     0,    49,     3,    30,    49,    48,    49,    31,    51,    37,
     0,    49,     3,    30,    49,    48,    50,     0,    50,     0,
    49,    38,     0,    44,    50,    38,     0,    39,    38,     0,
    40,    38,     0,    43,    38,     0,    42,    38,     0,    49,
     0,    25,    51,    45,    16,    51,    38,    26,    50,     0,
    18,    45,    24,    51,    38,    41,    49,    19,    50,     0,
    49,     0,    49,    17,    51,    38,     0,    16,    51,    38,
    49,    27,    45,    50,    26,    50,     0,    22,    49,     3,
    50,     0,    47,     9,    47,     0,    49,    21,    10,    47,
     0,    51,     0,    50,     0,     0,    47,    46,    47,     0,
     5,     0,     6,     0,    49,     4,    49,     0,    49,     3,
    49,     0,    47,     7,    47,     0,    47,     8,    47,     0,
     7,    47,     0,    49,    32,    47,    33,    49,     0,    20,
     0,    23,     0,    10,     0,     0,    49,    34,    51,    49,
     0,    49,    35,     0,    49,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    20,    21,    21,    21,    22,    22,    22,    22,    22,    22,
    22,    23,    24,    25,    25,    26,    27,    29,    29,    29,
    29,    29,    30,    31,    31,    32,    32,    32,    32,    32,
    32,    33,    33,    34,    34,    35,    36,    36
};

static const char * const yytname[] = {   "$","error","$undefined.","ID","NUM",
"RELOP","LOGOP","ADDOP","MULOP","ASSIGNOP","WS","SEP","RES","PROG","START","VAR",
"DO","ELSE","IF","ENDI","INT","PUT","GET","REAL","THEN","LOOP","ENDL","UNTIL",
"ENDP","'.'","':'","','","'('","')'","';'","'\\n'","Start","Vars","SttmntList",
"Loop","If","Else","Do","Get","Statement","BooleanStatement","BooleanOp","Literal",
"Type","Empty","EndLine","CR",""
};
#endif

static const short yyr1[] = {     0,
    36,    37,    37,    37,    38,    38,    38,    38,    38,    38,
    38,    39,    40,    41,    41,    42,    43,    44,    44,    44,
    44,    44,    45,    46,    46,    47,    47,    47,    47,    47,
    47,    48,    48,    49,    49,    50,    51,    51
};

static const short yyr2[] = {     0,
    11,     9,     6,     1,     2,     3,     2,     2,     2,     2,
     1,     8,     9,     1,     4,     9,     4,     3,     4,     1,
     1,     0,     3,     1,     1,     3,     3,     3,     3,     2,
     5,     1,     1,     1,     0,     4,     2,     1
};

static const short yydefact[] = {     0,
    35,    34,     0,    35,     0,     0,    35,    35,    38,    35,
     0,     0,     4,    37,    36,    35,     0,    35,    35,    35,
    35,    35,    35,    35,     0,    35,    35,    35,    35,    35,
     0,    11,    21,    20,     0,    30,     0,    35,     0,     0,
     0,    35,     0,     7,     8,    10,     9,    35,    35,    35,
    35,    35,    35,     0,    35,     5,    32,    33,    35,    35,
    35,    24,    25,    35,    35,     0,     1,     6,    28,    29,
    18,    27,    26,    35,     0,     0,     3,     0,    35,    23,
    17,    35,    19,    35,    35,    35,    35,    35,    31,    35,
    35,    35,    14,     0,     2,     0,     0,    35,    35,    35,
    35,    35,    12,    16,    13,    15,     0,     0,     0
};

static const short yydefgoto[] = {   107,
    11,    25,    26,    27,    92,    28,    29,    30,    39,    64,
    31,    59,    32,    33,    34
};

static const short yypact[] = {   -11,
    -2,-32768,     1,    -2,   -18,     9,    -2,    -2,    -5,    -2,
    28,     2,-32768,-32768,-32768,    -2,    14,   154,    -2,    18,
    -2,    18,    -2,    -2,    33,   154,   154,   154,   154,    -2,
    48,   133,-32768,-32768,    -6,    25,     7,   154,    22,    87,
    44,    18,    40,-32768,-32768,-32768,-32768,   154,    18,    18,
    18,    -2,    -2,    52,    18,-32768,-32768,-32768,    -2,    -2,
    -2,-32768,-32768,    18,    -2,    54,-32768,-32768,    25,    25,
    25,-32768,-32768,    18,     5,     3,-32768,    45,   154,    25,
-32768,    -2,    25,    -2,    -2,    18,    -2,   154,-32768,    -2,
    -2,    -2,    57,    49,-32768,    50,    59,    -2,    -2,    -2,
    -2,   154,-32768,-32768,-32768,-32768,    79,    96,-32768
};

static const short yypgoto[] = {-32768,
    12,    39,-32768,-32768,-32768,-32768,-32768,-32768,   -41,-32768,
    83,-32768,    -1,    23,    19
};


#define	YYLAST		188


static const short yytable[] = {     3,
    66,     1,     5,     4,    17,     9,    12,     2,    15,    52,
    53,    49,    50,    57,     9,     7,    58,    35,    37,     9,
    37,    41,     9,     8,    20,    10,     6,     2,     5,    14,
    13,    49,    50,    85,    18,     7,     7,    84,    55,    38,
    37,    16,    42,    19,    91,    61,    65,    37,    37,    37,
    72,    73,    48,    37,    49,    50,    51,    76,    78,     9,
    43,    74,    37,     5,    44,    45,    46,    47,    67,    82,
    56,    86,    37,    98,    99,   100,    60,   101,   108,    79,
     9,    77,    89,     9,    37,    93,    68,    81,    12,     5,
    97,    62,    63,    49,    50,   109,     9,     5,     5,     5,
    88,    95,    36,    90,    40,     0,     0,     0,     0,     0,
     0,     0,    13,    96,     0,     0,   102,    87,     0,     0,
     0,   103,   104,   105,    40,     0,    94,     0,     0,     0,
     0,    69,    70,    71,     0,    52,    53,    75,     0,    20,
   106,     0,     2,     0,     0,     0,    80,     0,    21,     0,
    22,     0,     0,    54,    23,     0,    83,    24,     0,     0,
    20,     0,     0,     2,    55,     0,     7,    14,    40,    21,
     0,    22,     0,     0,     0,    23,     0,     0,    24,     0,
     0,     0,     0,     0,     0,     0,     0,   -22
};

static const short yycheck[] = {     1,
    42,    13,     4,     3,     3,     7,     8,    10,    10,     3,
     4,     7,     8,    20,    16,    34,    23,    19,    20,    21,
    22,    23,    24,    15,     7,     7,     4,    10,    30,    35,
     8,     7,     8,    31,    16,    34,    34,    33,    32,    21,
    42,    14,    24,    30,    86,    24,     3,    49,    50,    51,
    52,    53,    30,    55,     7,     8,     9,    59,    60,    61,
    28,    10,    64,    65,    26,    27,    28,    29,    29,    16,
    32,    27,    74,    17,    26,    26,    38,    19,     0,    61,
    82,    59,    84,    85,    86,    87,    48,    65,    90,    91,
    92,     5,     6,     7,     8,     0,    98,    99,   100,   101,
    82,    90,    20,    85,    22,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    90,    91,    -1,    -1,    98,    79,    -1,    -1,
    -1,    99,   100,   101,    42,    -1,    88,    -1,    -1,    -1,
    -1,    49,    50,    51,    -1,     3,     4,    55,    -1,     7,
   102,    -1,    10,    -1,    -1,    -1,    64,    -1,    16,    -1,
    18,    -1,    -1,    21,    22,    -1,    74,    25,    -1,    -1,
     7,    -1,    -1,    10,    32,    -1,    34,    35,    86,    16,
    -1,    18,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 20 "lps.y"
{printf("SUCCESS!!\n");;
    break;}
case 19:
#line 29 "lps.y"
{ yyval = yyvsp[0]; printf("%d\n", yyval) ;
    break;}
case 26:
#line 32 "lps.y"
{ yyval = yylval; ;
    break;}
case 27:
#line 32 "lps.y"
{yyval = yylval;;
    break;}
case 28:
#line 32 "lps.y"
{yyval = yyvsp[-2] + yyvsp[-1];;
    break;}
case 29:
#line 32 "lps.y"
{yyval = yyvsp[-2] * yyvsp[-1];;
    break;}
case 30:
#line 32 "lps.y"
{yyval = -yyvsp[-1];
    break;}
case 31:
#line 32 "lps.y"
{yyval = yyvsp[-2];;
    break;}
case 37:
#line 36 "lps.y"
{lineCnt++;;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}

#line 37 "lps.y"


int main(int argc, char * argv[]){
    if(argc==1){
        fprintf(stderr,"No input");
        exit(1);
    }
    if (strstr(argv[1],".sle") == 0){
        fprintf(stderr, "Input file type not supported\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    strrchr(argv[1], '.')[0] = '\0';
    yyout = fopen(strcat(argv[1],".lst"), "w");

    yyparse();
    return 0;
}

void yyerror(char *err){
    printf("%s in line: %d, in: %s", err, lineCnt, yytext);
    fprintf(yyout,"%s\n%s in line: %d", yytext, err, lineCnt);
    exit(1);
}