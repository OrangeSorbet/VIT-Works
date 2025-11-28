#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    srand(time(NULL));

    int arrayOfNums[1000] = {};
    int size = 1000;

    for (int i = 0; i < size; i++)
    {
        arrayOfNums[i] = (rand()%100+1);
    }

    int maxSum = 0;
    int firstIndex = 0;
    int lastIndex = 0;

    for (int i = 0; i <= size - 10; i++)
    {
        int currentSum = 0;
        for (int j = i; j < i + 10; j++)
        {
            currentSum += arrayOfNums[j];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            firstIndex = i;
            lastIndex = i + 9;
        }
    }

    printf("\n The max sum of 10 consecutive elements: %d from index %d to %d \n", maxSum, firstIndex, lastIndex);
    printf("\n Want to see the entire array? (y/n) - ");
    char response = getchar();

    if(response == 'y' || response == 'Y')
    {
        for(int i=0; i<size; i++)
        {
            printf("%d, ", arrayOfNums[i]);
        }
    }
    return 0;
}
