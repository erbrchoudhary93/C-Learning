#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int capacity;
} DynamicArray;


void init_array(DynamicArray *arr)
{
    arr->size = 0;
    arr->capacity = 2;

    arr->data = malloc(arr->capacity * sizeof(int));

    if (arr->data == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
}


void push(DynamicArray *arr, int value)
{
    if (arr->size == arr->capacity)
    {
        int new_capacity = arr->capacity * 2;

        int *temp = realloc(
            arr->data,
            new_capacity * sizeof(int)
        );

        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            exit(1);
        }

        arr->data = temp;
        arr->capacity = new_capacity;
    }

    arr->data[arr->size] = value;

    arr->size++;
}


void print_array(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->data[i]);
    }

    printf("\n");
}


void destroy_array(DynamicArray *arr)
{
    free(arr->data);

    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}


int main()
{
    DynamicArray arr;

    init_array(&arr);

    push(&arr, 10);
    push(&arr, 20);
    push(&arr, 30);
    push(&arr, 40);
    push(&arr, 50);

    printf("Array: ");
    print_array(&arr);

    printf("Size: %d\n", arr.size);
    printf("Capacity: %d\n", arr.capacity);

    destroy_array(&arr);

    return 0;
}