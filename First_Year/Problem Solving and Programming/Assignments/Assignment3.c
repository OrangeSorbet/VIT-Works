#include <stdio.h>
int main()
{
 //Declaring choice as a switch case
 int choice;
 //Getting input
Name – Ashvij Patil
Division – B
Batch – 3
Roll. No. – 58
PRN - 12414673
 printf("To find the factorial of a number, press 1\n");
 printf("To find out if the number is prime or not, press 2\n");
 printf("Enter here - ");
 scanf("%d", &choice);
 //Declaring switch case
 switch (choice) {
 case 1:
 {
 int a, i, f=1;
 printf("Enter a number to find its factorial- ");
 scanf("%d", &a);
 for(i=1; i<=a; i++)
 {
 f = f*i;
 }
 printf("Factorial of number is %d", f);
 break;
 }
 case 2:
 {
 int n, i, flag = 0;
 printf("Enter a positive integer to see if it's prime- ");
 scanf("%d", &n);
 // 0 and 1 are not prime numbers
 // change flag to 1 for non-prime number
 if (n == 0 || n == 1)
 flag = 1;
 for (i = 2; i < n; i++) {
 // if n is divisible by i, then n is not prime
 // change flag to 1 for non-prime number
 if (n % i == 0) {
 flag = 1;
 break;
 }
 }
 // flag is 0 for prime numbers
 if (flag == 0)
 printf("%d is a prime number.", n);
 else
 printf("%d is not a prime number.", n);
 break;
 }
 }
 int main();
}