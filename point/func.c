#include <stdio.h>

void test() {
    printf("hello world\n");
}

int main(int argc, const char* argv) {
    ((void (*)())0x0000000000401136)();
    // will loop()? yes
    int a = ((int (*)(int, const char *))0x0000000000401147)(argc, argv);
    printf("return %d;\n", a);
    return 0;
}