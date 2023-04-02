#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

typedef int (__add)(int, int);

void call_add(__add cb) {
    printf("a + b = %d\n", cb(3, 4));
}

int main(int argc, char const *argv[]) {
  /* code */
  call_add(add);
  return 0;
}
