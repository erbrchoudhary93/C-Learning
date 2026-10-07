#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define INITIAL_CAPACITY 4


/* =========================================================
   DATA STRUCTURE
   ========================================================= */

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;

} DynamicArray;


/* =========================================================
   INPUT FUNCTIONS
   ========================================================= */

/*
    Read one line safely from stdin.

    Returns:
        1  -> success
        0  -> EOF / input closed
*/
int read_line(char *buffer, size_t size)
{
    if (fgets(buffer, size, stdin) == NULL)
    {
        return 0;
    }

    /*
        Remove trailing newline.
    */

    buffer[strcspn(buffer, "\n")] = '\0';

    return 1;
}


/*
    Read an integer safely.

    Example valid inputs:

        10
        -5
        0

    Invalid:

        abc
        10abc
        12.5
        empty
*/
int read_int(const char *prompt, int *value)
{
    char buffer[100];

    while (1)
    {
        printf("%s", prompt);

        if (!read_line(buffer, sizeof(buffer)))
        {
            return 0;
        }

        /*
            Empty input
        */

        if (buffer[0] == '\0')
        {
            printf("Input cannot be empty.\n");
            continue;
        }

        char *endptr;

        errno = 0;

        long result = strtol(buffer, &endptr, 10);

        /*
            Check conversion error.
        */

        if (errno == ERANGE ||
            result < INT_MIN ||
            result > INT_MAX)
        {
            printf("Number is out of range.\n");
            continue;
        }

        /*
            Check if entire input was a number.

            Example:

                123abc

            is invalid.
        */

        if (*endptr != '\0')
        {
            printf("Invalid number. Please enter an integer.\n");
            continue;
        }

        *value = (int)result;

        return 1;
    }
}


/*
    Read menu choice.
*/
int read_choice(int *choice)
{
    return read_int("Enter your choice: ", choice);
}


/* =========================================================
   DYNAMIC ARRAY FUNCTIONS
   ========================================================= */


/*
    Initialize Dynamic Array.
*/
int init_array(DynamicArray *arr)
{
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;

    arr->data = malloc(
        arr->capacity * sizeof(int)
    );

    if (arr->data == NULL)
    {
        printf("ERROR: Memory allocation failed.\n");
        return 0;
    }

    return 1;
}


/*
    Destroy Dynamic Array.
*/
void destroy_array(DynamicArray *arr)
{
    free(arr->data);

    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


/*
    Grow the array.

    Example:

        4 -> 8
        8 -> 16
        16 -> 32
*/
int grow_array(DynamicArray *arr)
{
    /*
        Check integer overflow before doubling.
    */

    if (arr->capacity > SIZE_MAX / 2)
    {
        printf("ERROR: Maximum array capacity reached.\n");
        return 0;
    }

    size_t new_capacity = arr->capacity * 2;

    int *temp = realloc(
        arr->data,
        new_capacity * sizeof(int)
    );

    if (temp == NULL)
    {
        printf("ERROR: Unable to grow array.\n");
        return 0;
    }

    arr->data = temp;
    arr->capacity = new_capacity;

    return 1;
}


/*
    PUSH

    Add element at the end.
*/
int push(DynamicArray *arr, int value)
{
    if (arr->size == arr->capacity)
    {
        if (!grow_array(arr))
        {
            return 0;
        }
    }

    arr->data[arr->size] = value;

    arr->size++;

    return 1;
}


/*
    POP

    Remove last element.
*/
int pop(DynamicArray *arr, int *removed_value)
{
    if (arr->size == 0)
    {
        return 0;
    }

    arr->size--;

    *removed_value = arr->data[arr->size];

    return 1;
}


/*
    GET

    Read element at index.
*/
int get_value(
    const DynamicArray *arr,
    size_t index,
    int *value
)
{
    if (index >= arr->size)
    {
        return 0;
    }

    *value = arr->data[index];

    return 1;
}


/*
    SET

    Change existing element.
*/
int set_value(
    DynamicArray *arr,
    size_t index,
    int value
)
{
    if (index >= arr->size)
    {
        return 0;
    }

    arr->data[index] = value;

    return 1;
}


/*
    INSERT

    Insert element at given index.

    Example:

        [10][20][30][40]

        insert(2, 99)

        [10][20][99][30][40]
*/
int insert_value(
    DynamicArray *arr,
    size_t index,
    int value
)
{
    /*
        index == size is allowed.

        Example:

            size = 4
            index = 4

        means insert at end.
    */

    if (index > arr->size)
    {
        return 0;
    }

    /*
        Need one extra slot.
    */

    if (arr->size == arr->capacity)
    {
        if (!grow_array(arr))
        {
            return 0;
        }
    }

    /*
        Shift elements RIGHT.

        IMPORTANT:

        Start from the end.

    */

    for (size_t i = arr->size; i > index; i--)
    {
        arr->data[i] = arr->data[i - 1];
    }

    arr->data[index] = value;

    arr->size++;

    return 1;
}


/*
    REMOVE

    Remove element at index.
*/
int remove_value(
    DynamicArray *arr,
    size_t index,
    int *removed_value
)
{
    if (index >= arr->size)
    {
        return 0;
    }

    *removed_value = arr->data[index];

    /*
        Shift elements LEFT.
    */

    for (size_t i = index; i < arr->size - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;

    return 1;
}


/*
    PRINT ARRAY
*/
void print_array(const DynamicArray *arr)
{
    if (arr->size == 0)
    {
        printf("\nArray is EMPTY.\n");
        printf("Size     : 0\n");
        printf("Capacity : %zu\n", arr->capacity);

        return;
    }

    printf("\n");
    printf("========================================\n");
    printf("              ARRAY\n");
    printf("========================================\n");

    printf("Index : ");

    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%zu ", i);
    }

    printf("\n");

    printf("Value : ");

    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }

    printf("\n");

    printf("----------------------------------------\n");

    printf("Size     : %zu\n", arr->size);
    printf("Capacity : %zu\n", arr->capacity);

    printf("========================================\n");
}


/* =========================================================
   MENU
   ========================================================= */

void print_menu(void)
{
    printf("\n");
    printf("========================================\n");
    printf("       DYNAMIC ARRAY MANAGER\n");
    printf("========================================\n");

    printf("  1. Push       - Add at end\n");
    printf("  2. Pop        - Remove from end\n");
    printf("  3. Get        - Read value\n");
    printf("  4. Set        - Update value\n");
    printf("  5. Insert     - Insert at index\n");
    printf("  6. Remove     - Remove from index\n");
    printf("  7. Print      - Display array\n");
    printf("  8. Info       - Show size/capacity\n");
    printf("  9. Clear      - Remove all elements\n");
    printf("  0. Exit\n");

    printf("========================================\n");
}


/* =========================================================
   INFO
   ========================================================= */

void print_info(const DynamicArray *arr)
{
    printf("\n");
    printf("Array Information\n");
    printf("-------------------------\n");

    printf("Size       : %zu\n", arr->size);
    printf("Capacity   : %zu\n", arr->capacity);

    if (arr->capacity > 0)
    {
        double usage =
            ((double)arr->size / arr->capacity) * 100.0;

        printf("Memory use : %.2f%%\n", usage);
    }

    printf("-------------------------\n");
}


/* =========================================================
   CLEAR
   ========================================================= */

void clear_array(DynamicArray *arr)
{
    arr->size = 0;
}


/* =========================================================
   MAIN
   ========================================================= */

int main(void)
{
    DynamicArray arr;

    /*
        Initialize array.
    */

    if (!init_array(&arr))
    {
        return EXIT_FAILURE;
    }


    printf("\n");
    printf("========================================\n");
    printf("   Welcome to Dynamic Array Manager\n");
    printf("========================================\n");

    printf("\nInstructions:\n");
    printf("- Enter numbers only when asked.\n");
    printf("- Array indexes start from 0.\n");
    printf("- GET/SET/REMOVE require an existing index.\n");
    printf("- INSERT allows index = size.\n");
    printf("- POP removes the last element.\n");


    while (1)
    {
        int choice;

        print_menu();

        if (!read_choice(&choice))
        {
            printf("\nInput closed. Cleaning up memory...\n");

            destroy_array(&arr);

            return EXIT_SUCCESS;
        }


        switch (choice)
        {
            /* =========================================
               PUSH
               ========================================= */

            case 1:
            {
                int value;

                printf("\n--- PUSH ---\n");

                if (!read_int(
                        "Enter value to add: ",
                        &value))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (push(&arr, value))
                {
                    printf(
                        "SUCCESS: %d added at index %zu.\n",
                        value,
                        arr.size - 1
                    );
                }

                break;
            }


            /* =========================================
               POP
               ========================================= */

            case 2:
            {
                int removed;

                printf("\n--- POP ---\n");

                if (pop(&arr, &removed))
                {
                    printf(
                        "SUCCESS: Removed %d.\n",
                        removed
                    );
                }
                else
                {
                    printf(
                        "ERROR: Cannot pop. Array is empty.\n"
                    );
                }

                break;
            }


            /* =========================================
               GET
               ========================================= */

            case 3:
            {
                int index;
                int value;

                printf("\n--- GET ---\n");

                if (!read_int(
                        "Enter index: ",
                        &index))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (index < 0)
                {
                    printf("ERROR: Index cannot be negative.\n");
                    break;
                }

                if (get_value(
                        &arr,
                        (size_t)index,
                        &value))
                {
                    printf(
                        "Value at index %d = %d\n",
                        index,
                        value
                    );
                }
                else
                {
                    printf(
                        "ERROR: Invalid index.\n"
                    );

                    printf(
                        "Valid indexes: 0 to %zu\n",
                        arr.size == 0
                            ? 0
                            : arr.size - 1
                    );
                }

                break;
            }


            /* =========================================
               SET
               ========================================= */

            case 4:
            {
                int index;
                int value;

                printf("\n--- SET ---\n");

                if (!read_int(
                        "Enter index: ",
                        &index))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (index < 0)
                {
                    printf("ERROR: Index cannot be negative.\n");
                    break;
                }

                if (!read_int(
                        "Enter new value: ",
                        &value))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (set_value(
                        &arr,
                        (size_t)index,
                        value))
                {
                    printf(
                        "SUCCESS: Index %d updated to %d.\n",
                        index,
                        value
                    );
                }
                else
                {
                    printf(
                        "ERROR: Invalid index.\n"
                    );
                }

                break;
            }


            /* =========================================
               INSERT
               ========================================= */

            case 5:
            {
                int index;
                int value;

                printf("\n--- INSERT ---\n");

                printf(
                    "Valid index: 0 to %zu\n",
                    arr.size
                );

                if (!read_int(
                        "Enter index: ",
                        &index))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (index < 0)
                {
                    printf("ERROR: Index cannot be negative.\n");
                    break;
                }

                if (!read_int(
                        "Enter value: ",
                        &value))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (insert_value(
                        &arr,
                        (size_t)index,
                        value))
                {
                    printf(
                        "SUCCESS: %d inserted at index %d.\n",
                        value,
                        index
                    );
                }
                else
                {
                    printf(
                        "ERROR: Invalid index or memory allocation failed.\n"
                    );
                }

                break;
            }


            /* =========================================
               REMOVE
               ========================================= */

            case 6:
            {
                int index;
                int removed;

                printf("\n--- REMOVE ---\n");

                if (arr.size == 0)
                {
                    printf(
                        "ERROR: Array is empty.\n"
                    );

                    break;
                }

                printf(
                    "Valid index: 0 to %zu\n",
                    arr.size - 1
                );

                if (!read_int(
                        "Enter index: ",
                        &index))
                {
                    destroy_array(&arr);
                    return EXIT_SUCCESS;
                }

                if (index < 0)
                {
                    printf("ERROR: Index cannot be negative.\n");
                    break;
                }

                if (remove_value(
                        &arr,
                        (size_t)index,
                        &removed))
                {
                    printf(
                        "SUCCESS: Removed %d from index %d.\n",
                        removed,
                        index
                    );
                }
                else
                {
                    printf(
                        "ERROR: Invalid index.\n"
                    );
                }

                break;
            }


            /* =========================================
               PRINT
               ========================================= */

            case 7:

                print_array(&arr);

                break;


            /* =========================================
               INFO
               ========================================= */

            case 8:

                print_info(&arr);

                break;


            /* =========================================
               CLEAR
               ========================================= */

            case 9:

                clear_array(&arr);

                printf(
                    "SUCCESS: Array cleared.\n"
                );

                break;


            /* =========================================
               EXIT
               ========================================= */

            case 0:

                printf(
                    "\nFreeing allocated memory...\n"
                );

                destroy_array(&arr);

                printf(
                    "Goodbye! Program terminated safely.\n"
                );

                return EXIT_SUCCESS;


            /* =========================================
               INVALID MENU
               ========================================= */

            default:

                printf(
                    "ERROR: Invalid choice.\n"
                );

                printf(
                    "Please select a number from 0 to 9.\n"
                );

                break;
        }
    }


    /*
        Technically unreachable,
        but keeps cleanup explicit.
    */

    destroy_array(&arr);

    return EXIT_SUCCESS;
}