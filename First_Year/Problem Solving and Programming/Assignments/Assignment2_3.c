#include <stdio.h>

int main() {
    //Declare variables
    int a, b;

    //Get input
    printf("Enter the numbers to compare them - ");
    scanf("%d", &a);
    scanf("%d", &b);

    //Compare numbers and print result
    if (a=b)
    {
        printf("%d and %d are equal", a, b);
    }
    else if (a>b)
    {
        printf("%d is bigger than %d", a, b);
    }
    else
    {
        printf("%d is bigger than %d", b, a);
    }
}
