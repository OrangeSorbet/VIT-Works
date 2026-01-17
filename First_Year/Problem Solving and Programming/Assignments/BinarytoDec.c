#include <stdio.h>
#include <math.h>

int main()
{
    int num, rem, dec, total, i, digit;

    printf("Enter a binary number to convert into decimal- ");
    scanf("%d", &num);

    while(num!=0)
    {
        rem = num % 10;
        dec = dec + (rem*pow(2, i));
        digit = num/10;
        num = digit;
        i++;
    }
    total = dec;
    printf("%d", total);
    return 0;
}
