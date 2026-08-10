// What is a C program?
// A C program is a sequence of instructions that the computer executes.

// #include <stdio.h>

// int main()
// // main() is the entry point of a C program.
// // When you execute the program, execution starts here.
// // int means main() returns an integer.
// {
//     printf("Hello, World!\n");

//     return 0;
// }

// Variables
// A variable is a named region of memory used to store a value.

// Declaration:
// int age;

// Initialization:
// int age = 25;

// Assignment:
// age = 30;

// C Data Types
// C provides several fundamental data types.
// The most important ones initially are:
// char
// int
// float
// double

#include <stdio.h>
#include <stdbool.h>

// int main()
// {
//     int age = 25;
//     int count = 100;
//     // int temperature = -10;
//     float price = 99.99f;
//     float temperature = 36.5f;   
//     double pi = 3.141592653589793;   
//     char grade = 'A';
// //     float   → 4 bytes
//         // double  → 8 bytes

//     printf("%d\n", age);
//     printf("%d\n", count);
//     printf("%f\n", temperature);
//     printf("%lf\n", pi);
//     printf("%c\n", grade);

//     // Character is actually an integer
//     // Because character 'A' has numeric value 65 in ASCII.?

//     char c = 'A';

//     printf("%c\n", c);
//     printf("%d\n", c);

//     bool is_logged_in = true;
//     printf("%d\n", is_logged_in);   
//     printf("%d\n", !is_logged_in);

// //     Type       Purpose
// // char       character / small integer
// // int        integer
// // float      decimal number
// // double     higher-precision decimal number
// // bool       true/false

//     return 0;
// }

// #include <stdio.h>
// #include <stdbool.h>

// int main()
// {
//     char grade = 'A';
//     int age = 25;
//     float height = 5.9f;
//     double pi = 3.141592653589793;
//     bool student = true;

//     printf("Grade: %c\n", grade);
//     printf("Age: %d\n", age);
//     printf("Height: %f\n", height);
//     printf("Pi: %lf\n", pi);
//     printf("Student: %d\n", student);

//     return 0;
// }

// sizeof()
// Now we reach a very important C concept.
// C provides:
// sizeof()
// It tells you how many bytes an object/type occupies.
// Example:

// #include <stdio.h>

// int main()
// {
//     printf("char: %zu bytes\n", sizeof(char));
//     printf("int: %zu bytes\n", sizeof(int));
//     printf("float: %zu bytes\n", sizeof(float));
//     printf("double: %zu bytes\n", sizeof(double));

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     printf("short: %zu\n", sizeof(short));
//     printf("int: %zu\n", sizeof(int));
//     printf("long: %zu\n", sizeof(long));
//     printf("long long: %zu\n", sizeof(long long));

//     return 0;
// }

// Constants
// Sometimes you don't want a value to change.

const int MAX_USERS = 100;
// #include <stdio.h>

// int main()
// {
//     const int DAYS = 7;

//     printf("%d\n", DAYS);

//     return 0;
// }

// Operators

// Now we need to learn how variables interact.

// Arithmetic operators
// +   addition
// -   subtraction
// *   multiplication
// /   division
// %   remainder

// #include <stdio.h>

// int main()
// {
//     int a = 10;
//     int b = 3;

//     printf("%d\n", a + b);
//     printf("%d\n", a - b);
//     printf("%d\n", a * b);
//     printf("%d\n", a / b);
//     printf("%d\n", a % b);

//     return 0;
// }

// Comparison operators

// These are essential for control flow.

// ==   equal
// !=   not equal
// >    greater than
// <    less than
// >=   greater than or equal
// <=   less than or equal

// Logical operators
// &&    AND
// ||    OR
// !     NOT

// Control Flow
// if
// else
// else if
// switch
// for
// while
// do while

// #include <stdio.h>

// int main()
// {
//     int age = 20;

//     if (age >= 18)
//     {
//         printf("You are an adult\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int age = 185;

//     if (age >= 18)
//     {
//         printf("Adult\n");
//     }
//     else
//     {
//         printf("Minor\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int marks = 75;

//     if (marks >= 90)
//     {
//         printf("Grade A+\n");
//     }
//     else if (marks >= 80)
//     {
//         printf("Grade A\n");
//     }
//     else if (marks >= 70)
//     {
//         printf("Grade B\n");
//     }
//     else if (marks >= 60)
//     {
//         printf("Grade C\n");
//     }
//     else
//     {
//         printf("Fail\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int age = 25;
//     int has_id = 0;

//     if (age >= 18)
//     {
//         if (has_id)
//         {
//             printf("Entry allowed\n");
//         }
//     }

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int day = 3;

//     switch (day)
//     {
//         case 1:
//             printf("Monday\n");
//             break;

//         case 2:
//             printf("Tuesday\n");
//             break;

//         case 3:
//             printf("Wednesday\n");
//             break;

//         case 4:
//             printf("Thursday\n");
//             break;

//         default:
//             printf("Invalid day\n");
//     }

//     return 0;
// }

// for loop

// A loop repeats code.

// Basic structure:

// for (initialization; condition; update)
// {
//     // code
// }

// #include <stdio.h>

// int main()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d\n", i);
//     }

//     return 0;
// }

// while loop
// A while loop continues while a condition is true.

// #include <stdio.h>

// int main()
// {
//     int i = 0;

//     while (i < 5)
//     {
//         printf("%d\n", i);

//         i++;
//     }

//     return 0;
// }

// do ... while
// do
// {
//     // code
// }
// while (condition);

// #include <stdio.h>

// int main()
// {
//     int i = 0;

//     do
//     {
//         printf("%d\n", i);

//         i++;
//     }
//     while (i < 0);

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         if (i == 5)
//         {
//             break;
//         }

//         printf("%d\n", i);
//     }

//     return 0;
// }

// continue
// continue skips the current iteration.

// #include <stdio.h>

// int main()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         if (i == 5)
//         {
//             continue;
//         }

//         printf("%d\n", i);
//     }

//     return 0;
// }

// A complete example
// Let's combine variables, data types, conditions and loops.

// #include <stdio.h>

// int main()
// {
//     int age = 25;
//     float height = 5.9f;
//     char grade = 'A';

//     printf("Age: %d\n", age);
//     printf("Height: %.2f\n", height);
//     printf("Grade: %c\n", grade);

//     if (age >= 18)
//     {
//         printf("Adult\n");
//     }
//     else
//     {
//         printf("Minor\n");
//     }

//     for (int i = 1; i <= 5; i++)
//     {
//         printf("Count: %d\n", i);
//     }

//     return 0;
// }


// Input with scanf

// #include <stdio.h>

// int main()
// {
//     int age;

//     printf("Enter your age: ");

//     scanf("%d", &age);

//     printf("Your age is %d\n", age);

//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int a;
//     int b;

//     printf("Enter two numbers: ");

//     scanf("%d %d", &a, &b);

//     printf("Sum = %d\n", a + b);

//     return 0;
// }

// Mini Project — Number Analyzer

// #include <stdio.h>

// int main()
// {
//     int number;

//     printf("Enter a number: ");
//     scanf("%d", &number);

//     if (number > 0)
//     {
//         printf("Positive\n");
//     }
//     else if (number < 0)
//     {
//         printf("Negative\n");
//     }
//     else
//     {
//         printf("Zero\n");
//     }

//     if (number % 2 == 0)
//     {
//         printf("Even\n");
//     }
//     else
//     {
//         printf("Odd\n");
//     }

//     return 0;
// }

// Mini Project — Multiplication Table

#include <stdio.h>

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n",
               number,
               i,
               number * i);
    }

    return 0;
}