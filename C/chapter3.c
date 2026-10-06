#include <stdio.h>

int main()
{
    int number = 100;

    int *ptr = &number;

    printf("===== POINTER DEMO =====\n\n");

    printf("number = %d\n", number);

    printf("Address of number = %p\n", (void *)&number);

    printf("ptr = %p\n", (void *)ptr);

    printf("Value using *ptr = %d\n", *ptr);

    printf("\nChanging value using pointer...\n");

    *ptr = 500;

    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);

    return 0;
}
