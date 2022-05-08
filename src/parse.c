#include "stack.h"

void replace(char *str) {
  char *functs[] = constchar;
  char *replace = "sctpvdqnom";
  for (unsigned long int i = 0; i < strlen(str); i++) {
    for (int j = 0; j < 10; j++) {
      if (strncmp(&str[i], functs[j], strlen(functs[j])) == 0) {
        str[i] = replace[j];
        int d = i;
        for (int p = d + 1; str[p] != '\0'; p++) {
          str[p] = str[d + strlen(functs[j])];
          d++;
        }
        // printf("\ncheck: %s\n", str);
      }
    }
  }
}

int is_trigonometry(char operat) {
  int flag = 0;
  if (operat== 's' || operat== 'c' || operat== 't' || operat== 'p' ||
      operat== 'v' ||
      operat== 'd' ||
      operat== 'q' ||
      operat== 'n' ||
      operat== 'o')
    flag = 1;
  return flag;
}

float calculations(stack_1 *st, stack_2 *ct, int prior) {
  float res = 0;
  // printf("\nalal %d\n", priority(ct->b[ct->n - 1]));
  // printf("\nalal %d\n", prior);
  if (ct->n >= 1 && prior <= priority(ct->b[ct->n - 1]) &&
      ct->b[ct->n - 1] != '(') {
    // printf("\nya zawel suyda\n");
    char operat;
    float operand1, operand2;
    operat = popc(ct);
    if (!is_trigonometry(operat)) {
      operand1 = popd(st);
      operand2 = popd(st);
    } else {
      operand1 = popd(st);
    }
    // printf("\noperat:\t%c\n", operat);
    switch (operat) {
      case ('+'):
        res = operand2 + operand1;
        pushd(st, res);
        break;
      case ('-'):
        res = operand2 - operand1;
        pushd(st, res);
        break;
      case ('*'):
        res = operand2 * operand1;
        pushd(st, res);
        break;
      case ('/'):
        res = operand2 / operand1;
        pushd(st, res);
        break;
      case ('s'):
        res = sin(operand1);
        pushd(st, res);
        break;
      case ('c'):
        res = cos(operand1);
        pushd(st, res);
        break;
      case ('t'):
        res = tan(operand1);
        pushd(st, res);
        break;
      case ('p'):
        res = asin(operand1);
        pushd(st, res);
        break;
      case ('v'):
        res = acos(operand1);
        pushd(st, res);
        break;
      case ('d'):
        res = atan(operand1);
        pushd(st, res);
        break;
      case ('q'):
        res = sqrt(operand1);
        pushd(st, res);
        break;
      case ('n'):
        res = log(operand1);
        pushd(st, res);
        break;
      case ('o'):
        res = log10(operand1);
        pushd(st, res);
        break;
      case ('^'):
        res = pow(operand2, operand1);
        pushd(st, res);
        break;
      case ('m'):
        res = fmod(operand2, operand1);
        pushd(st, res);
        break;
    }
    // printf("\nresult:\t%f\n", res);
  }
  return res;
}

int parse_operats(stack_1 *st, stack_2 *ct, char *str, int i) {
  if (str[i] == '+') {
    calculations(st, ct, 1);
    if (priority(ct->b[ct->n - 1]) != 2 && priority(ct->b[ct->n - 1]) != 3 &&
        priority(ct->b[ct->n - 1]) != 4) {
      pushc(ct, str[i]);
      i++;
    }
  }
  if (str[i] == '-') {
    if (str[i - 1] == '(') {
      i++;
      pushd(st, atof(&str[i]) * (-1));
      while ((isdigit(str[i]) || str[i] == '.') && str[i] != '\0') {
        i++;
      }
    } else {
      calculations(st, ct, 1);
      if (priority(ct->b[ct->n - 1]) != 1) {
        pushc(ct, str[i]);
        i++;
      }
    }
  }
  if (str[i] == '*') {
    calculations(st, ct, 2);
    pushc(ct, str[i]);
    i++;
  }
  if (str[i] == '/') {
    calculations(st, ct, 2);
    pushc(ct, str[i]);
    i++;
  }
  if (str[i] == '(') {
    pushc(ct, str[i]);
    i++;
  }
  if (str[i] == ')') {
    int d = i;
    do {
      calculations(st, ct, 0);
      d++;
      if (ct->b[ct->n - 1] == '(') {
        popc(ct);
        break;
      }
    } while (str[d] != '(');
    i++;
  }
  if (str[i] == '^') {
    calculations(st, ct, 3);
    pushc(ct, str[i]);
    i++;
  }
  if (str[i] == 'm') {
    calculations(st, ct, 2);
    pushc(ct, str[i]);
    i++;
  }
  if (is_trigonometry(str[i])) {
    pushc(ct, str[i]);
    i++;
  }
  // printc(ct);
  return i;
}

int parse_operands(stack_1 *st, char *str, int i) {
  if (atof(&str[i])) {
    pushd(st, atof(&str[i]));
    while ((isdigit(str[i]) || str[i] == '.') && str[i] != '\0') {
      i++;
    }
    // printd(st);
  }
  return i;
}

float parse(char *str) {
  replace(str);
  float res = 0;
  stack_1 s;
  stack_2 c;
  stack_1 *st = &s;
  stack_2 *ct = &c;
  initd(st);
  initc(ct);
  int i = 0;
  do {
    // printf("\npreved\n");
    while (!isdigit(str[i]) && str[i] != '.' && str[i] != '\0') {
      i = parse_operats(st, ct, str, i);
      // printc(ct);
    }
    i = parse_operands(st, str, i);
  } while (str[i] != '\0');

  do {
    calculations(st, ct, priority(ct->b[ct->n - 1]));
  } while (ct->n > 0);
  res = popd(st);
  return res;
}

int priority(char operat) {
  int prior = 0;
  if (operat== '+' || operat== '-') prior = 1;
  if (operat== '*' || operat== '/' || operat== 'm') prior = 2;
  if (operat== '^') prior = 3;
  if (is_trigonometry(operat)) prior = 4;
  if (operat== '(') prior = 7;
  return prior;
}

int check(char *str) {
  int err = 0;
  int lb = 0;
  int rb = 0;
  for (unsigned long int i = 0; i <= strlen(str); i++) {
  if (str[i]>= '*' && str[i] <= '/' && str[i + 1]>= '*' && str[i + 1] <= '/') err = 1;
  if (str[i] == '(') lb++;
  if (str[i] == ')') rb++;
  }
  for (unsigned long int i = 0; i <= strlen(str); i++) {
  if (atof(&str[i])) {
    int dot = 0;
    while ((isdigit(str[i]) || str[i] == '.') && str[i] != '\0') {
      if (str[i] == '.') {
        dot++;
      }
    i++;
    if (dot > 1) err = 1;
    }
  }
  }
  if (lb != rb) err = 1;
  return err;
}

// int main() {
// char str[N] = "asin(0.5)+acos(0.5)+atan(0.5)+2^2";
// float res;
// res = parse(str);
// printf("%f\n", res);
// printf("%f", asin(0.5)+acos(0.5)+atan(0.5)+pow(2, 2));
// }

