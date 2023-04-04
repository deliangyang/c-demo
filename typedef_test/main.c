#include <stdio.h>
#include <memory.h>

// union 共享同一块类型，长度为max(sizeof(.memeber))
typedef union test
{
    int a;
    char b;
} test;

// typedef struct <unnamed> test1. unnamed struct
typedef struct
{
    int a;
} test1;

union test_char
{
    char first[3];
    char second[10];
};


int main(int argc, char const *argv[])
{
    union test tt = {
        .a = 1, 
        .b = 'a'
    };
    test1 t1 = {.a=3};
    printf("a = %c\n", tt.a);
    printf("b = %c\n", tt.b);
    printf("t1.a = %d\n", t1.a);

    printf("union sizeof(test.a): %d\n", sizeof(tt.a));
    printf("union sizeof(test.b): %d\n", sizeof(tt.b));
    printf("union sizeof(int): %d\n", sizeof(int));
    printf("union sizeof(char): %d\n", sizeof(char));
    printf("union sizeof(union test): %d\n", sizeof(union test));

    union test_char tt2 = {
        .first={'a', 'd', 'e'},
        .second={'c', 'd', 'e', 'f', 'g', 'd', 'x'},
    };
    
    printf("test_char: %c%c%c\n", tt2.first[0], tt2.first[1], tt2.first[2]);
    printf("test_char: %c%c%c\n", tt2.second[0], tt2.second[1], tt2.second[2]);
    char x[3] = {'a', 'c', 'd'};
    memcpy(&tt2.first, &x, sizeof(x));
    // tt2.first = {'a', 'c', 'd'};
    printf("test_char: %c%c%c\n", tt2.first[0], tt2.first[1], tt2.first[2]);
    printf("test_char: %c%c%c\n", tt2.second[0], tt2.second[1], tt2.second[2]);
    printf("test_char: %c%c%c\n", tt2.first[4], tt2.second[5], tt2.second[6]);
    return 0;
}
