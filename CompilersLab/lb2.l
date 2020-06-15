%{
#include "lps_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* file_tok;

//typedef enum{ID=1,NUM, RELOP, LOGOP, ADDOP, MULOP, ASSIGNOP, WS, SEP, RES,START,DO ,ELSE, IF, ENDI, INT, PUT, PROG, GET, REAL, THEN, VAR, LOOP, ENDL, UNTIL, ENDP} tok; 
  
%}

digit		[0-9]
letter    	[a-zA-Z]
id 			{letter}({letter}|{digit})*
num 		{digit}+|{digit}*\.{digit}+
relop 		=|<>|<|>  
logop		&|!
addop 		\+|-
mulop 		\*|\/|mod
assignop	<= 
WS		[ \t]+
%x comment
%%

"/*"		BEGIN comment;
<comment>"*/"	BEGIN INITIAL;
<comment>.|\n	;
start		return START;
do			return DO;
else		return ELSE;
if			return IF;
endi 		return ENDI;
int			return INT;
put			return PUT;
prog		return PROG;
get			return GET;
real		return REAL;
then		return THEN;
var			return VAR;
loop		return LOOP;
endl		return ENDL;		
until		return UNTIL;
endp		return ENDP;


{addop} 	return ADDOP;
{mulop} 	return MULOP;
{id} 		return ID;
{num} 		return NUM;
{relop} 	return RELOP;  
{logop}		return LOGOP;

{assignop}	return ASSIGNOP;
{WS}		return WS;
"("|")"		return SEP;

"."         return '.';
";"         return ';';
":"         return ':';
","     return ',';
\n              return '\n';
.		{printf("find Error"); return 0;}

%%

int yywrap(){return 1;}