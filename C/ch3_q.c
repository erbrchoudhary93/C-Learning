// #include <stdio.h>

// x          → address
// *p          → value at address
// p++         → next element
// p--         → previous element
// p + i       → आगे i elements
// *(p + i)    → i-th element
// p1 - p2     → elements के बीच distance

// int main()
// {
//     int arr[] = {10, 20, 30, 40, 50};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     printf("sizeof arr = %zu\n", sizeof(arr));
//     printf("arr = %d\n", arr[0]);
//     printf("sizeof arr[0] = %zu\n", sizeof(arr[0]));
//     printf("===== POINTERS AND ARRAYS =====\n\n");
//     printf("Size of array: %d\n", size);
//     printf("Array elements using pointer arithmetic:\n");

//     int *p = arr;

//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", *p);
//         p++;
//     }

//     printf("\n");

//     return 0;
// }

// #include <stdio.h>

// int find_max(int *arr, int size)
// {
//     int max = *arr;

//     for (int i = 0; i < size; i++)
//     {
//         printf("max = %d\n", max);
//         if (*(arr + i) > max)
//         {
//             max = *(arr + i);
//         }
//     }

//     return max;
// }

// int main()
// {
//     int arr[] = {12, 45, 7, 89, 23};

//     int size = sizeof(arr) / sizeof(arr[0]);

//     int result = find_max(arr, size);

//     printf("Maximum = %d\n", result);

//     return 0;
// }



// #include <stdio.h>

// void reverse_array(int *arr, int size)
// {
//     int *left = arr;
//     printf("left = %p\n", (void *)left);
//     printf("arr = %d\n", *arr);
//     int *right = arr + size - 1;
//     printf("right = %p\n", (void *)right);

//     while (left < right)
//     {
//         int temp = *left;

//         *left = *right;
//         *right = temp;

//         left++;
//         right--;
//     }
// }

// void print_array(int *arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     printf("\n");
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5,8,7,6,9,10};

//     int size = sizeof(arr) / sizeof(arr[0]);

//     printf("Before: ");
//     print_array(arr, size);

//     reverse_array(arr, size);

//     printf("After:  ");
//     print_array(arr, size);

//     return 0;
// }

#include <stdio.h>

int search(int *arr, int size, int target)
{
    int *ar = arr;

    while (ar < arr + size)
    {
        if (*ar == target)
        {
            return ar - arr;
        }

        ar++;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 70;

    int index = search(arr, size, target);

    if (index != -1)
    {
        printf("Found at index = %d\n", index);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}