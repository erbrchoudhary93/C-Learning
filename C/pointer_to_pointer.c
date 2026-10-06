#include <stdio.h>

int main()
{
    int x = 20;

    int *p = &x;

    int **pp = &p;

    **pp = 50;

    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", **pp);

    return 0;
}