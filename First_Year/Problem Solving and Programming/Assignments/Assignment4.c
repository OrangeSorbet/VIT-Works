#include <stdio.h>
int choice, i, j, size, arr[100], total=0, min=0, num=0;

void read()
{
    printf("Enter size of array to be read - ");
    scanf("%d", &size);
    //input numbers in array
    printf("Enter numbers in array and press enter after each number - ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display()
{
    //display array
    printf("Inputted array is - [");
    for(int i=0; i<size; i++)
    {
        if(i!=0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int main() {
do {
    //menu
    printf("---------------------------------\n");
    printf("1. Read array\n");
    printf("2. Print array\n");
    printf("3. Print Addition of array elements\n");
    printf("4. Find minimum number from array\n");
    printf("5. Search an element and print location from given array\n");
    printf("6. Exit\n");
    printf("---------------------------------\n");
    printf("Enter your choice - ");
    scanf("%d", &choice);

    //switch
    switch (choice)
    {
    case 1:
        read();
        display();
        break;

    case 2:
        read();
        //display array
        display();
        break;

    case 3:
        read();
        //Addition Loop
        for(i=0; i<size; i++)
        {
            total+=arr[i];
        }
        printf("Sum of the given digits in array is %d\n", total);
        break;

    case 4:
        read();
        display();

        //computing phase
        for(int a=0; a<size; ++a)
        {
           for(int b=a+1; b<size; ++b)
            {
                if(arr[a]>arr[b])
                {
                    min=arr[b];
                    arr[b]=arr[a];
                    arr[a]=min;
                }
            }
        }
        //display array
        printf("Ascending order of the given array is - [");
        for(int i=0; i<size; i++)
        {
            if(i!=0)
            {
                printf(", ");
            }
            printf("%d", arr[i]);
        }
        printf("]\n");

        //min value
        printf("Minimum value is %d\n", arr[0]);
        break;

    case 5:
        read();
        display();
        //enter number to find index of
        printf("Enter a number to find it's position in the array - ");
        scanf("%d", &num);

        //computing phase
        for(int i=0; i<size; i++)
        {
            if(num==arr[i])
            {
                printf("Index of %d is %d\n", num, i);
                printf("ie. it is on position %d\n", i+1);
            }
        }
        break;

    case 6:
        exit(0);
        break;
    }
}
while (choice!=6);
getch();
}
