#include <stdio.h>

int main()
{
    int num, flag=0, i;
    printf("Enter number to check if it's odd or even- ");
    scanf("%d", &num);

    if(num==0||num==1)
    flag=1;

    for(i=3; i<=num; i++)
    {
        if(num%i==0)
            flag=1;
        break;
    }

    if(num==2)
        flag=0;

    if(flag==1)
    {
        printf("%d is not a prime number", num);

    }
    else
    {
        printf("%d is a prime number", num);
    }

}
