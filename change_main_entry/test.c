
#include <stdio.h>
#include <stdlib.h>

__attribute__((constructor)) void before_main() {
 printf("hello %s\n", __FUNCTION__);
}

__attribute__((destructor)) void after_main() {
 printf("hello %s\n", __FUNCTION__);
}


void test() {
    printf("aa\n");
}

int main() {
    printf("hello world\n");
    // return 0;
    test();
    exit(0);
}