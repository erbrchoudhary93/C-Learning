

// Functions

// int add(int a, int b)
// {
//     return a + b;
// }

#include <stdio.h>

void hello()
{
    printf("Hello!\n");
}

// int main()
// {
//     hello();

//     return 0;
// }

// Function with parameters

// #include <stdio.h>

// void greet(int age)
// {
//     printf("You are %d years old\n", age);
// }

// int main()
// {
//     greet(25);

//     return 0;
// }

// #include <stdio.h>

// int add(int a, int b)
// {
//     return a + b;
// }

// int main()
// {
//     int result;

//     result = add(10, 20);

//     printf("Result = %d\n", result);

//     return 0;
// }

// Function declaration / prototype

#include <stdio.h>



void print_message()
{
    printf("Hello from function\n");
}

// Function with no parameters

// void hello(void)
// {
//     printf("Hello\n");
// }

// Functions can also call other functions:
int square(int x)
{
    return x * x;
}

int calculate(int x)
{
    return square(x) + 10;
}

int add(int a, int b);

int main()
{
    int result = add(10, 20);
     print_message();

    printf("%d\n", result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}