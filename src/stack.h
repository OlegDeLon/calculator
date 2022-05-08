#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define constchar \
  { "sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "ln", "log", "mod" }
//    s      c       t      p       v       d       q      n      o     m
typedef double Data;

typedef struct {
  Data a[N];
  int n;
} stack_1;

typedef char operand;

typedef struct {
  char b[N];
  int n;
} stack_2;

void initd(stack_1* st);
void pushd(stack_1* st, Data data);
Data popd(stack_1* st);
void initc(stack_2* ct);
void pushc(stack_2* ct, operand operand);
operand popc(stack_2* ct);
int is_trigonometry(char operat);
int priority(char operat);
float calculations(stack_1 *st, stack_2 *ct, int prior);
int parse_operators(stack_1 *st, stack_2 *ct, char *str, int i);
int parse_operands(stack_1 *st, char *str, int i);
float parse(char *str);
int check(char *str);
#endif  //  SRC_STACK_H_

