#include "varList.h"
var vars[MAX_LEN];
int curr = 0;

VarType getType(char *t)
{
    if (strcmp(t, "int") == 0)
        return Int;
    else if (strcmp(t, "real") == 0)
        return Float;
    else
        return None;
}
char *getData(char *nm)
{
    var *v = getVar(nm);
    char *res = (char *)malloc(sizeof(char) * MAX_LEN);
    res[0] = '\0';
    if (v == NULL)
    {
        printf("ERROR! %s is undeclared! ", nm);
        return NULL;
    }

    if (v->type == Int)
        sprintf(res, "%d", *(int *)v->data);
    else if (v->type == Float)
        snprintf(res, MAX_LEN, "%f\0", *(float *)v->data);
    else
        printf("ERROR!\n");

    return res;
}

var *insertVar(char *nm, char *vType)
{
    var *v = getVar(nm);
    if (v == NULL)
    {
        v = vars + curr;
        v->type = getType(vType);
        vars[curr++].name = nm;
        if (v->type == Int)
            v->data = (int *)malloc(sizeof(int));
        else
            v->data = (float *)malloc(sizeof(float));
    }
    else
        printf("ERROR! %s already exists!\n", nm);
}
int setData(char *nm, char *value)
{
    var *v = getVar(nm);
    if (value == NULL)
        return 0;

    if (!isdigit(value[0]) && value[0] != '-')
        if ((value = getData(value)) == NULL)
            return 0;

    if (v != NULL)
    {
        if (v->type == Int)
        {
            if (strchr(value, '.') == NULL)
                *(int *)v->data = atoi(value);
            else{
                printf("ERROR! can't assign float to int!\n");
                return 0;
            }
        }
        else
            *(float *)v->data = atof(value);
    }
    return 1;
}
var *getVar(char *nm)
{
    int i;
    for (i = 0; i < curr; i++)
        if (strcmp(vars[i].name, nm) == 0)
            return vars + i;
    return NULL;
}

void printVars()
{
    int i;
    for (i = 0; i < curr; i++)
        printf("%s = %s\n", vars[i].name, getData(vars[i].name));
}
char *MathOp(char *nm1, char op, char *nm2)
{
    if (nm1 == NULL || nm2 == NULL)
    {
        return NULL;
    }
    
    char *res = (char *)malloc(sizeof(char) * MAX_LEN);
    VarType t1 = Int, t2 = Int;

    if (strchr(nm1, '.') != NULL)
        t1 = Float;

    if (strchr(nm2, '.') != NULL)
        t2 = Float;

    switch (op)
    {
    case '+':
        if (t1 == Int && t2 == Int)
            sprintf(res, "%d", atoi(nm1) + atoi(nm2));
        else if (t1 == Int && t2 == Float)
            sprintf(res, "%f", atoi(nm1) + atof(nm2));
        else if (t1 == Float && t2 == Int)
            sprintf(res, "%f", atof(nm1) + atoi(nm2));
        else if (t1 == Float && t2 == Float)
            sprintf(res, "%f", atof(nm1) + atof(nm2));
        break;
    case '-':
        if (t1 == Int && t2 == Int)
            sprintf(res, "%d", atoi(nm1) - atoi(nm2));
        else if (t1 == Int && t2 == Float)
            sprintf(res, "%f", atoi(nm1) - atof(nm2));
        else if (t1 == Float && t2 == Int)
            sprintf(res, "%f", atof(nm1) - atoi(nm2));
        else if (t1 == Float && t2 == Float)
            sprintf(res, "%f", atof(nm1) - atof(nm2));
        break;
    case '*':
        if (t1 == Int && t2 == Int)
            sprintf(res, "%d", atoi(nm1) * atoi(nm2));
        else if (t1 == Int && t2 == Float)
            sprintf(res, "%f", atoi(nm1) * atof(nm2));
        else if (t1 == Float && t2 == Int)
            sprintf(res, "%f", atof(nm1) * atoi(nm2));
        else if (t1 == Float && t2 == Float)
            sprintf(res, "%f", atof(nm1) * atof(nm2));
        break;
    case '/':
        if (t1 == Int && t2 == Int && atoi(nm2) != 0)
            sprintf(res, "%d", atoi(nm1) / atoi(nm2));
        else if (t1 == Int && t2 == Float && atof(nm2) != 0)
            sprintf(res, "%f", atoi(nm1) / atof(nm2));
        else if (t1 == Float && t2 == Int && atoi(nm2) != 0)
            sprintf(res, "%f", atof(nm1) / atoi(nm2));
        else if (t1 == Float && t2 == Float && atof(nm2) != 0)
            sprintf(res, "%f", atof(nm1) / atof(nm2));
        else
            printf("ERROR! can't divide by 0!\n");

        break;
    case 'm':
        if (t1 == Int && t2 == Int && atoi(nm2) != 0)
            sprintf(res, "%d", atoi(nm1) % atoi(nm2));
        else if (atoi(nm2) == 0)
            printf("ERROR! can't mod by 0!\n");
        else
            printf("ERROR! can mod only integers!\n");
        break;

    default:
        printf("ERROR! Illegal math function!\n");
        break;
    }
    return res;
}