#include <stdio.h>

struct Student {
    int age;
    int marks;
};

void updateMarks(struct Student *p)
{
    p->marks = 95;
}

int main()
{
    struct Student s = {18, 80};

    printf("Before: %d\n", s.marks);

    updateMarks(&s);

    printf("After: %d\n", s.marks);

    return 0;
}