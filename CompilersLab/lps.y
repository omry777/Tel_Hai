%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdarg.h>
#define MAX_VARS 30
#define MAX_VAR_NAME 20
#define ERRCODE 0x8fffffff

typedef struct{
    double data;
    char id[MAX_VAR_NAME];
}var;

extern int linenum;
extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;
var vars[MAX_VARS];
int varCnt = 0;

int yylex();
void yyerror(char *err);
double insertToVar(char* id, double num);
double getVar(char* id);
void printVar(char *id)
void printVars();

%}

typedef %union {
    int  num;                 /* integer value */
    char id[MAX_VAR_NAME];              /* symbol table id */
}STYPE;
#define YYSTYPE STYPE

%token <num> NUM
%token <id> ID

%token RELOP LOGOP ADDOP MULOP ASSIGNOP WS SEP RES PROG START VAR
%token DO ELSE IF ENDI INT PUT GET REAL THEN LOOP ENDL UNTIL ENDP

%type <num> Start Vars SttmntList Loop If Else Do Get

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

Statement : Literal ASSIGNOP Literal | Empty PUT WS Literal { $$ = $4; printf("%g\n", 1.0) } | CR | EndLine |
BooleanStatement:  Literal BooleanOp Literal
BooleanOp:  RELOP | LOGOP
Literal :   Empty NUM Empty { $$ = yylval; } | Empty ID Empty {$$ = yylval;} | Literal ADDOP Literal {$$ = $1 + $2;} | Literal MULOP Literal {$$ = $1 * $2;} | ADDOP Literal {$$ = -$1}| Empty '(' Literal ')' Empty {$$ = $3;}
Type :      INT | REAL
Empty:      WS |
EndLine:    Empty ';' CR Empty
CR :        Empty '\n' | Empty
%%

int main(int argc, char * argv[]){
    if(argc==1){
        fprintf(stderr,"No input");
        return 1;
    }
    if (strstr(argv[1],".sle") == 0){
        fprintf(stderr, "Input file type not supported\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    strrchr(argv[1], '.')[0] = '\0';
    yyout = fopen(strcat(argv[1],".lst"), "w");

    yyparse();
    return 0;
}

void yyerror(char *err){
    printf("%s in line: %d, in: %s", err, linenum, yytext);
    fprintf(yyout,"%s\n%s in line: %d", yytext, err, linenum);
    exit(1);
}

int insertToVar(char* id, double num)
{
  int i;
  for( i = 0; i < varCnt; i++)
    if(!strcmp( id, vars[i].id)){
      vars[i].data = num;
      return 0;
    }
  if(varCnt < MAX_VARS){
    strcpy(vars[varCnt].id, id);
    vars[varCnt++].data = num;
    return 0;
  }
  return ERRCODE;
}

double getVar(char* id)
{
  int i;
  for( i = 0; i < varCnt; i++){
    if(!strcmp(vars[i].id, id))
      return vars[i].data ;
  }
  return ERRCODE;
} 

void printVar(char *id){
    double v = getVar(id);

    if (v != ERRCODE){
        if ((int)v == v)
            printf("%d", v);
        else
            printf("%g", v);
    }
}

void printVars()
{
  int i;
  for(i=0; i<varCnt ; i++){
    printVar(vars[i].id);
  }
}

