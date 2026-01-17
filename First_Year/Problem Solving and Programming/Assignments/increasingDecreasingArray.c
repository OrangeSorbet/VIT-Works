#include <stdio.h>
//Variables
int inc[100], dec[100], decision, size=0, min=0, max=0;

void read() {
    for(int i=0; i<size; i++)
        {
            scanf("%d", &inc[i]);
        }
}

void display() {
    printf("Inputted array is - [");
        for(int i=0; i<size; i++)
        {
            if(i!=0)
            {
                printf(", ");
            }
            printf("%d", inc[i]);
        }
        printf("]\n");
}

int main() {
    //switch case initialization
    printf("Press 1 to get increasing order\nPress 2 to get decreasing order - ");
    scanf("%d", &decision);

    switch (decision)
    {
    case 1: //for increasing order
        //get size of array
        printf("Enter size of array - ");
        scanf("%d", &size);
        //fill numbers in array
        printf("Enter numbers to get them in increasing order - ");
        read(inc);

        display(inc);

        //computing phase
        for(int a=0; a<size; ++a)
        {
           for(int b=a+1; b<size; ++b)
            {
                if(inc[a]>inc[b])
                {
                    min=inc[b];
                    inc[b]=inc[a];
                    inc[a]=min;
                }
            }
        }
        //display array
        printf("Ascending order of the given array is - [");
        display(inc);

        //min value
        printf("Minimum value is %d", inc[0]);
        break;

    case 2: //for decreasing order
        //get size of array
        printf("Enter size of array - ");
        scanf("%d", &size);
        printf("Enter numbers to get them in decreasing order - ");
        read(inc);
        display(inc);

        //computing phase
        for(int a=0; a<size; ++a)
        {
           for(int b=a+1; b<size; ++b)
            {
                if(inc[a]<inc[b])
                {
                    max=inc[b];
                    inc[b]=inc[a];
                    inc[a]=max;
                }
            }
        }

        display(inc);

        //min value
        printf("Maximum value is %d", inc[0]);
        break;
        break;
    }
}
