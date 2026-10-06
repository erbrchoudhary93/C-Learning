// #include <stdio.h>

// int main()
// {
//     char name[] = "Ram";

//     char *p = name;

//     printf("String: %s\n", name);

//     printf("Characters using pointer:\n");

//     while (*p != '\0')
//     {
//         printf("%c\n", *p);
//         p++;
//     }

//     return 0;
// }
// #include <stdio.h>

// int string_length(char *str)
// {
//     int count = 0;

//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }

//     return count;
// }

// int main()
// {
//     char name[] = "Hello";

//     int length = string_length(name);

//     printf("Length = %d\n", length);

//     return 0;
// }
// str       // address
// *str      // उस address पर character/value
// str++     // अगले character के address पर जाना

// #include <stdio.h>

// int count_vowels(char *str)
// {
//     int count = 0;

//     while (*str != '\0')
//     {
//         char ch = *str;

//         if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
//             ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
//         {
//             count++;
//         }

//         str++;
//     }

//     return count;
// }

// int main()
// {
//     char text[] = "Education";

//     int result = count_vowels(text);

//     printf("Vowels = %d\n", result);

//     return 0;
// }

// #include <stdio.h>

// void to_uppercase(char *str)
// {
//     while (*str != '\0')
//     {
//         if (*str >= 'a' && *str <= 'z')
//         {
//             *str = *str - 32;
//         }

//         str++;
//     }
// }

// int main()
// {
//     char text[] = "hello world";

//     printf("Before: %s\n", text);

//     to_uppercase(text);

//     printf("After:  %s\n", text);

//     return 0;
// }

// #include <stdio.h>

// void reverse_string(char *str)
// {
//     char *left = str;
//     char *right = str;

//     while (*right != '\0')
//     {
//         right++;
//     }

//     right--;

//     while (left < right)
//     {
//         char temp = *left;
//         *left = *right;
//         *right = temp;

//         left++;
//         right--;
//     }
// }

// int main()
// {
//     char text[] = "hello";

//     printf("Before: %s\n", text);

//     reverse_string(text);

//     printf("After:  %s\n", text);

//     return 0;
// }

#include <stdio.h>

int is_palindrome(char *str)
{
    char *left = str;
    char *right = str;

    while (*right != '\0')
    {
        right++;
    }

    right--;

    while (left < right)
    {
        if (*left != *right)
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main()
{
    char text[] = "madam";

    if (is_palindrome(text))
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    return 0;
}