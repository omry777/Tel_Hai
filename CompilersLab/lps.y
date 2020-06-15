%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineCnt = 1;
extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;

int yylex();
void yyerror(char *err);
%}

%token ID NUM RELOP LOGOP ADDOP MULOP ASSIGNOP WS SEP RES PROG START VAR
%token DO ELSE IF ENDI INT PUT GET REAL THEN LOOP ENDL UNTIL ENDP

%start Start
%%
Start :         PROG Empty ID EndLine VAR Vars START CR SttmntList ENDP '.' {printf("SUCCESS!!\n");}
Vars :          Empty ID ':' Empty Type Empty ',' CR Vars | Empty ID ':' Empty Type EndLine | EndLine
SttmntList:     Empty SttmntList | Statement EndLine SttmntList | Loop SttmntList | If SttmntList | Get SttmntList | Do SttmntList | Empty
Loop:           LOOP CR BooleanStatement DO CR SttmntList ENDL EndLine
If:             IF BooleanStatement THEN CR SttmntList Else Empty ENDI EndLine
Else:           Empty | Empty ELSE CR SttmntList
Do:             DO CR SttmntList Empty UNTIL BooleanStatement EndLine ENDL EndLine
Get:            GET Empty ID EndLine

Statement : Literal ASSIGNOP Literal | Empty PUT WS Literal { $$ = $4; printf("%d\n", $$) } | CR | EndLine |
BooleanStatement:  Literal BooleanOp Literal
BooleanOp:  RELOP | LOGOP
Literal :   Empty NUM Empty { $$ = yylval; } | Empty ID Empty {$$ = yylval;} | Literal ADDOP Literal {$$ = $1 + $2;} | Literal MULOP Literal {$$ = $1 * $2;} | ADDOP Literal {$$ = -$1}| Empty '(' Literal ')' Empty {$$ = $3;}
Type :      INT | REAL
Empty:      WS |
EndLine:    Empty ';' CR Empty
CR :        Empty '\n' {lineCnt++;} | Empty
%%

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