#ifndef VARLIST_H
#define VARLIST_H
#define MAX_NAME_LEN 20
#define MAX_LEN 30
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum VarType {None, Int, Float} VarType;

typedef struct var{
    void *data;
    VarType type;
    char *name;
} var;

var *insertVar(char *nm, char *vType);
void setData(char *nm, char *value);
var *getVar(char *nm);
void printVars();
char *MathOp(char *nm1, char op, char *nm2);
char *getData(char *nm);
#endif