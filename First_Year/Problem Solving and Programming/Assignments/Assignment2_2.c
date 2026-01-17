#include <stdio.h>
int main() {
 int a, b, sum = 0;
 // Read two numbers from the user
 printf("Enter two integers: ");
 scanf("%d", &a);
 scanf("%d", &b);
 // Calculate the addition of a and b
 // using '+' operator
 sum = a + b;
 printf("Sum: %d", sum);
 return 0;
}