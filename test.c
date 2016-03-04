#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct test_s
{
    int a;
    int b;
}test_t;

int main(int args,char *argv[])
{
    test_t t[2] = {{1,2},{3,4}};
    return 0;
}
