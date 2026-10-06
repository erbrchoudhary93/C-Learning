#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;   // p stores address of a

    int x = 2;
    int y = x << 4; 
    printf("x = %d, y = %d\n", x, y);

    printf("a = %d\n", a);
    printf("address of a = %p\n", (void *)&a);
    printf("p = %p\n", (void *)p);
    printf("value at p = %d\n", *p);

    *p = 25;       // change value of a through pointer
    printf("new a = %d\n", a);

    return 0;
}