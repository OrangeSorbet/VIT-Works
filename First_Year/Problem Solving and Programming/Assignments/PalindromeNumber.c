#include <stdio.h>

int main()
{
    int n, reverse=0, r, temp;
    printf("Enter number to see if it's a palindrome- ");
    scanf("%d", &n);
    temp=n;

    while(n!=0)
    {
        r = n % 10;
        reverse = reverse * 10 + r;
        n = n/10;
    }

    if(temp==reverse)
    {
        printf("It is a palindrome");
    }
    else
    {
        printf("It is not a palindrome");
    }
}
