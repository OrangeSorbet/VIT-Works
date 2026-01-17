#include <stdio.h>

int main() {
    //define variables
    int decision, ind[100], size, num;

    //accept switch decision
    printf("Press 1 to get index of the number in array\nPress 2 to get number in index of array - ");
    scanf("%d", &decision);

    //get size of array
    printf("Enter size of array - ");
    scanf("%d", &size);

    //input numbers in array
    printf("Enter numbers in array and press enter after each number - ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &ind[i]);
    }

    //display array
    printf("Inputted array is - [");
    for(int i=0; i<size; i++)
    {
        if(i!=0)
            printf(", ");
        printf("%d", ind[i]);
    }
    printf("]\n");

    //switch case for finding index of number or finding number in index
    switch (decision)
    {
    case 1: //getting index of number
        //enter number to find index of
        printf("Enter a number to find it's position in the array - ");
        scanf("%d", &num);

        //computing phase
        for(int i=0; i<size; i++)
        {
            if(num==ind[i])
            {
                printf("Index of %d is %d\n", num, i);
                printf("ie. it is on position %d\n", i+1);
            }
        }
        break;

    case 2: //finding number on that position
        //computing phase
        do
        {
            printf("Enter a position to find the number in the array - ");
            scanf("%d", &num);
            if(num>0 && num<=size)
            {
                printf("The number at position %d is %d", num, ind[num-1]);
            }
            else
            {
                printf("Position exceeds the size\n");
            }
        }
        while(num<=0 || num>size);
        break;
    }
}
