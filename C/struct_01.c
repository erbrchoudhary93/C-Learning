#include <stdio.h>

struct Student {
    int age;
    int marks;
};

int main()
{
    struct Student students[3] = {
        {18, 75},
        {19, 82},
        {18, 90}
    };

    struct Student *p = students;

    printf("Student 1: Age = %d, Marks = %d\n",
           p[0].age, p[0].marks);

    printf("Student 2: Age = %d, Marks = %d\n",
           p[1].age, p[1].marks);

    printf("Student 3: Age = %d, Marks = %d\n",
           p[2].age, p[2].marks);

    return 0;
}