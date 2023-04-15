#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

enum token {
  start,
  left,
  right,
  add,
  sub,
  ddiv,
  mul,
  number,
  eof,
};

struct value {
  enum token token;
  union val {
    float f;
    int i;
  } a;
};

int read_integer(char *s, int *idx);

int main(int argc, char const *argv[]) {
  char *s = "123 -+ /* 1 12";
  // printf("enter expr: ");
  // fgets(s, 1024, stdin);
  puts(s);
  int i;
  char c;
  struct value values[100];
  memset(values, 0, sizeof(struct value));
  int idx = 0;
  while (c = s[i]) {
    switch (c) {
    case '+':
      values[idx++].token = add;
      break;
    case '-':
      values[idx++].token = sub;
      break;
    case '*':
      values[idx++].token = mul;
      break;
    case '/':
      values[idx++].token = ddiv;
      break;
    case '(':
      values[idx++].token = left;
      break;
    case ')':
      values[idx++].token = right;
      break;
    case ' ':
      break;
    case '\0':
    case '\n':
      values[idx++].token = eof;
      break;
    }
    if (c >= '0' && c <= '9') {
      int intval = read_integer(&s[i], &i);
      struct value iv = {.a.i = intval, .token = number};
      values[idx++] = iv;
    } else if (c == '\0') {
        values[idx++].token = eof;
    }
    i++;
  }

  for (int i = 0; i < 100; i++) {
    if (values[i].token == eof) {
      break;
    } else if (values[i].token == number) {
      printf("token: %d, value: %d\n", values[i].token, values[i].a.i);
    } else {
      printf("token: %d\n", values[i].token);
    }
  }
  return 0;
}

int read_integer(char *s, int *idx) {
  char ss[10] = {0}; // ? 内存复用？
  // memset(ss, 0, sizeof(char));
  printf("%s, %d, %c，0x%p\n", ss, *idx, *s, s);
  int i = 0;
  char c;

  while (c = *s) {
    if (c >= '0' && c <= '9') {
      ss[i++] = c;
      printf("------->%c, %d, %s\n", c, i, ss);
    } else {
      break;
    }
    (*idx)++;
    *s++;
  }
  return atoi(ss);
}