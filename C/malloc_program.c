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

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;

    arr = malloc(5 * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}