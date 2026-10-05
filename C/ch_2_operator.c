#include <stdio.h>

struct Student {
    int age;
    int marks;
};

int main()
{
    struct Student s = {20, 80};

    struct Student *p = &s;

    printf("Before:\n");
    printf("Age = %d\n", s.age);
    printf("Marks = %d\n", s.marks);

    p->age = 25;
    p->marks = 90;

    printf("\nAfter:\n");
    printf("Age = %d\n", s.age);
    printf("Marks = %d\n", s.marks);

    return 0;
}