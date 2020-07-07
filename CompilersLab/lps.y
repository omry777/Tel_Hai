%{
#include "varList.h"

int yylex();
void yyerror(char *err);
char *allocText();
void printNum(char *num);

extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;
int lineCnt = 1;
%}
%union{
  char *str;
  char c;
}

%token ID NUM RELOP LOGOP MULOP ASSIGNOP WS SEP RES PROG START VAR
%token DO ELSE IF ENDI INT PUT GET REAL THEN LOOP ENDL UNTIL ENDP
%left RELOP
%left ADDOP
%left MULOP
%token <str> ADDOP
%type <str> Type GetID Literal
%type <c> GetSign

%start Start
%%
Start :         PROG Empty ID EndLine VAR Vars START CR SttmntList ENDP '.' {printf("SUCCESS!!\n");}
              | PROG Empty ID EndLine VAR Vars START CR SttmntList ENDP  {yyerror("missing a '.'");}
              | PROG Empty ID EndLine VAR Vars START CR SttmntList {yyerror("missing ENDP");}
              | PROG Empty ID EndLine VAR Vars error {yyerror("missing start");} CR SttmntList ENDP '.'
Vars :          Vars1 ',' CR Vars | Vars1 EndLine | EndLine
Vars1:          GetID ':' Empty Type Empty { insertVar($1, $4) }
SttmntList:     Empty SttmntList | Statement EndLine SttmntList | Loop SttmntList | If SttmntList | Get SttmntList | Do SttmntList | Empty
Loop:           LOOP Empty BooleanStatement DO CR SttmntList ENDL EndLine
If:             IF BooleanStatement THEN CR SttmntList Else Empty ENDI EndLine
Else:           Empty | Empty ELSE CR SttmntList
Do:             DO CR SttmntList Empty UNTIL BooleanStatement EndLine ENDL EndLine
Get:            GET GetID EndLine {setData($2, "1"); }

Statement : GetID Empty ASSIGNOP Literal { if(!setData($1, $4)) yyerror("");} | Empty PUT WS Literal { printf("%s\n", $4); } | CR | EndLine | GetID Empty ASSIGNOP error {yyerror("Not a legal assignment!");}
BooleanStatement:  Literal Empty BooleanOp Literal Empty
BooleanOp:  RELOP | LOGOP
Literal :   Empty NUM { $$ = allocText(); } | Empty ID { $$ = getData(yytext); if($$ == NULL) yyerror(""); } | Literal GetSign Literal { $$ =  MathOp($1, $2, $3);} | GetSign Literal {if ($1 == '-') $$ = MathOp($2,'*',"-1");} | Empty '(' Literal Empty ')' {$$ = $3}
Type :      INT { $$ = allocText(); } | REAL { $$ = allocText(); }
Empty:      WS |
EndLine:    Empty ';' CR | Empty error {yyerror("No ';' in end of command!");} CR 
CR :        Empty '\n' {lineCnt++;}
GetID:      Empty ID { $$ = allocText(); }
GetSign:    Empty ADDOP { $$ = allocText()[0]; } | Empty MULOP { $$ = allocText()[0]; }
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
    printf("%s in line: %d \n", err, lineCnt);
    fprintf(yyout,"%s\n%s in line: %d", yytext, err, lineCnt);
}

char *allocText(){
  char *st = (char *)malloc(sizeof(char) * strlen(yytext));
  strcpy(st,yytext);
  return st;
}