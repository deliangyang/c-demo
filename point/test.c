#include <stdio.h>

void add(int *i) {
    (*i)++;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    add(&a);
    add(&a);
    add(&a);
    add(&a);
    printf("a = %d\n", a);
    return 0;
}
