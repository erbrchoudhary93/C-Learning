#include <stdio.h>

// int main(){
//     printf("Hello, World!\n");
//     int age = 25;
//     age = 30;
//     float price = 99.99;
//     double pi = 3.14159;
//     char name = 'A';
//     float weight;

//     printf("Age: %d\n", age);
//     printf("Price: %f\n", price);
//     printf("Value of Pi :%lf",pi);
//     printf("Name : %c\n",name);
     
//     printf("Enter new age: \n");
//     scanf("%d", &age);
//     printf("Enter your weight: \n");
//     scanf("%f", &weight);
//     printf("Enter your Name: \n");
//     scanf(" %c", &name);
//     printf("Updated Age: %d\n", age);
//     printf("weight : %f\n", weight);
//     printf("New Name : %c\n", name);

//     return 0;
// }
 int main() {
    printf("Enter value of a: \n");
    int a;
    scanf("%d", &a);
    printf("Enter value of b : \n");
    int b;
    scanf("%d", &b);
    int sum;
    sum = a + b;
    printf("Sum of a and b is : %d\n", sum);
    printf("reminder of a and b is : %d\n", a%b);
    printf("product of a and b is : %d\n " , a*b);
    printf("subtraction of a and b is : %d\n", a-b);
    if (b!=0){
      printf("division of a and b is : %d\n", a/b);

    }
   else{
      printf("value of b is zero, division not possible\n");
   }
    return 0;
 }