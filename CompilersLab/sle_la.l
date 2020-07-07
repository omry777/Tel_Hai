%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lps_tab.h"
#define ret(x) {fprintf(yyout, "%s", yytext); return x;}

static int lineCount = 1;
int MAX_SIZE = 1000;
char* get_token_attr(int token);
char* get_token_type(int token);
FILE* token_file;
%}

digit       [0-9]
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
relop       =|<|>|<>
assignop    <=|==|>=
logop       &|!
addop       \+|-
num         {addop}*{digit}+|{digit}*\.{digit}+|-{digit}
mulop       \*|\/|mod
WS          [ \t]+
%x          comment
%%

"/*"            BEGIN comment;
<comment>"*/"   BEGIN INITIAL;
<comment>.|\n   ;
start       ret(START);
do          ret(DO);
else        ret(ELSE);
if			ret(IF);
endi 		ret(ENDI);
int			ret(INT);
put			ret(PUT);
prog		ret(PROG);
get			ret(GET);
real		ret(REAL);
then		ret(THEN);
var			ret(VAR);
loop		ret(LOOP);
endl		ret(ENDL);		
until		ret(UNTIL);
endp		ret(ENDP);

{addop}     {ret(ADDOP);}
{mulop} 	{ret(MULOP);}
{id} 		{ ret(ID)};
{num} 		{ ret(NUM); }
{relop} 	ret(RELOP);  
{logop}		ret(LOGOP);
{assignop}  ret(ASSIGNOP);
{WS}        ret(WS);

"("         ret('(');
")"		    ret(')');

"."         ret('.');
";"         ret(';');
":"         ret(':');
","         ret(',');
\n          {lineCount++; ret('\n');}
.		    {printf("Found a syntax error in line: %d, at: %s\n", lineCount, yytext);fprintf(yyout,"%s\nFound a syntax error in line %d, at: %s\n",yytext, lineCount, yytext); exit(1);}
%%

int yywrap(){
    return 1;
}
