// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *p;

//     p = malloc(sizeof(int));

//     if (p == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     *p = 100;

//     printf("Value = %d\n", *p);

//     free(p);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *arr;

//     arr = malloc(5 * sizeof(int));

//     if (arr == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     arr[0] = 10;
//     arr[1] = 20;
//     arr[2] = 30;
//     arr[3] = 40;
//     arr[4] = 50;

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     free(arr);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *malloc_array;
    int *calloc_array;
    int *temp;

    // -------------------------------
    // 1. malloc() का use
    // -------------------------------
    malloc_array = malloc(3 * sizeof(int));

    if (malloc_array == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    malloc_array[0] = 10;
    malloc_array[1] = 20;
    malloc_array[2] = 30;

    printf("malloc array:\n");
    printf("%d %d %d\n\n",
           malloc_array[0],
           malloc_array[1],
           malloc_array[2]);


    // -------------------------------
    // 2. calloc() का use
    // -------------------------------
    calloc_array = calloc(3, sizeof(int));

    if (calloc_array == NULL)
    {
        printf("calloc failed\n");

        free(malloc_array);
        return 1;
    }

    printf("calloc array (initial values):\n");
    printf("%d %d %d\n\n",
           calloc_array[0],
           calloc_array[1],
           calloc_array[2]);


    // -------------------------------
    // 3. realloc() का use
    // -------------------------------
    temp = realloc(malloc_array, 5 * sizeof(int));

    if (temp == NULL)
    {
        printf("realloc failed\n");

        free(malloc_array);
        free(calloc_array);

        return 1;
    }

    malloc_array = temp;

    // नई memory में values डालना
    malloc_array[3] = 40;
    malloc_array[4] = 50;

    printf("After realloc (size increased to 5):\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", malloc_array[i]);
    }

    printf("\n");


    // -------------------------------
    // Memory release
    // -------------------------------
    free(malloc_array);
    free(calloc_array);

    return 0;
}