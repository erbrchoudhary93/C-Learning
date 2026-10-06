#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     int *p;

//     p = malloc(sizeof(int));

//     *p = 100;

//     printf("Value = %d\n", *p);
//     printf("Address = %p\n", (void *)p);

//     free(p);

//     return 0;
// }

// int main()
// {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     int *arr = malloc(n * sizeof(int));
//     if (arr == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return 1;
//     }   
//     for (int i = 0; i < n; i++)
//     {
//         *(arr + i) = (i + 1) * 10;
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
        
//         printf("Element %d: %d\n", i + 1, *(arr + i));
//         sum += *(arr + i);
//     }
//     printf("Sum of elements: %d\n", sum);
//     free(arr);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initial values
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = (i + 1) * 10;
    }

    printf("Before realloc:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    printf("\n");

    // Increase memory
    int *temp = realloc(arr, (n + 5) * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory reallocation failed\n");
        free(arr);
        return 1;
    }

    arr = temp;

    // Add new values
    for (int i = n; i < n + 5; i++)
    {
        *(arr + i) = (i + 1) * 10;
    }

    printf("After realloc:\n");

    for (int i = 0; i < n + 5; i++)
    {
        printf("%d ", *(arr + i));
    }

    printf("\n");

    free(arr);

    return 0;
}