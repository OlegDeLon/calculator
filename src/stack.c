#include "stack.h"

void initd(stack_1* st) { st->n = 0; }

void pushd(stack_1* st, Data data) {
  st->a[st->n] = data;
  st->n++;
}

Data popd(stack_1* st) {
  Data res = st->a[st->n - 1];
  st->n--;
  return res;
}

void initc(stack_2* ct) { ct->n = 0; }

void pushc(stack_2* ct, operand operand) {
  ct->b[ct->n] = operand;
  ct->n++;
}

operand popc(stack_2* ct) {
  operand res = ct->b[ct->n - 1];
  ct->n--;
  return res;
}


