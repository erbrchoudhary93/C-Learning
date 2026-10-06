#include <stdio.h>
#include <string.h>

/*
    CHAPTER 2
    Functions + Arrays + Strings
*/

/* =========================
   FUNCTION 1: Add two numbers
   ========================= */
int add(int a, int b)
{
    return a + b;
}

/* =========================
   FUNCTION 2: Find sum of array
   ========================= */
int array_sum(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

/* =========================
   FUNCTION 3: Find maximum
   ========================= */
int array_max(int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

/* =========================
   FUNCTION 4: Find minimum
   ========================= */
int array_min(int arr[], int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

/* =========================
   FUNCTION 5: Print array
   ========================= */
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* =========================
   FUNCTION 6: Count even numbers
   ========================= */
int count_even(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }

    return count;
}

/* =========================
   FUNCTION 7: Search array
   ========================= */
int search_array(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

/* =========================
   FUNCTION 8: Main
   ========================= */
int main()
{
    printf("=================================\n");
    printf("       C CHAPTER 2 DEMO\n");
    printf(" Functions + Arrays + Strings\n");
    printf("=================================\n\n");

    /*
        --------------------------------
        PART 1: FUNCTIONS
        --------------------------------
    */

    printf("===== FUNCTIONS =====\n");

    int a = 10;
    int b = 20;

    int result = add(a, b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a + b = %d\n\n", result);


    /*
        --------------------------------
        PART 2: ARRAYS
        --------------------------------
    */

    printf("===== ARRAYS =====\n");

    int numbers[] = {10, 20, 30, 40, 50};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array: ");
    print_array(numbers, size);

    printf("Array size = %d\n", size);

    printf("First element = %d\n", numbers[0]);
    printf("Last element = %d\n", numbers[size - 1]);

    /*
        Modify an array element
    */
    numbers[2] = 100;

    printf("After changing index 2 to 100:\n");

    print_array(numbers, size);

    /*
        Array calculations
    */
    printf("Sum = %d\n", array_sum(numbers, size));

    printf("Maximum = %d\n", array_max(numbers, size));

    printf("Minimum = %d\n", array_min(numbers, size));

    printf("Even numbers = %d\n", count_even(numbers, size));


    /*
        --------------------------------
        PART 3: SEARCH ARRAY
        --------------------------------
    */

    printf("\n===== ARRAY SEARCH =====\n");

    int target = 40;

    int index = search_array(numbers, size, target);

    if (index != -1)
    {
        printf("%d found at index %d\n", target, index);
    }
    else
    {
        printf("%d not found\n", target);
    }


    /*
        --------------------------------
        PART 4: STRINGS
        --------------------------------
    */

    printf("\n===== STRINGS =====\n");

    char name[] = "Ram";

    printf("Name = %s\n", name);

    printf("String length = %zu\n", strlen(name));

    printf("First character = %c\n", name[0]);

    printf("Second character = %c\n", name[1]);

    printf("Third character = %c\n", name[2]);


    /*
        --------------------------------
        PART 5: STRING INPUT
        --------------------------------
    */

    printf("\n===== STRING INPUT =====\n");

    char user_name[100];

    printf("Enter your name: ");

    fgets(user_name, sizeof(user_name), stdin);

    printf("Hello, %s", user_name);


    /*
        --------------------------------
        PART 6: ARRAY OF STRINGS
        --------------------------------
    */

    printf("\n===== ARRAY OF STRINGS =====\n");

    char students[3][50] =
    {
        "Ram",
        "Amit",
        "Rahul"
    };

    for (int i = 0; i < 3; i++)
    {
        printf("Student %d: %s\n", i + 1, students[i]);
    }


    /*
        --------------------------------
        FINISH
        --------------------------------
    */

    printf("\n=================================\n");
    printf("        PROGRAM FINISHED\n");
    printf("=================================\n");

    return 0;
}