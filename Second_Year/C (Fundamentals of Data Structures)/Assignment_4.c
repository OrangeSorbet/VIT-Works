#include <stdio.h>
#include "4.stack_queue_array.h"

int main() {
    Stack s;
    Queue q;

    s_init(&s);
    q_init(&q);
    int val;
    while(1) {
        printf("Queue and Stack Demo\n");
        printf("--------------------\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Exit\n");
        int choice1;
        printf("Enter choice - ");
        if (scanf("%d", &choice1) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice1) 
        {
        case 1:
            printf("--------------------\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Read\n");
            printf("--------------------\n");
            int choices;
            printf("Enter choice - ");
            if (scanf("%d", &choices) != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar() != '\n');
                break;
            }

            switch (choices)
            {
            case 1:
                printf("Enter value to push - ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }

                s_push(&s, val);
                break;
            case 2:
                val = s_pop(&s);
                printf("Popped value is %d\n", val);
                break;
            case 3:
                printf("Top to bottom values in stack:\n");
                s_read(&s);
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("--------------------\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Read\n");
            printf("--------------------\n");
            int choiceq;
            printf("Enter choice - ");
            if (scanf("%d", &choiceq) != 1) {
                printf("Invalid input. Please enter an integer.\n");
                while(getchar() != '\n');
                break;
            }

            switch (choiceq)
            {
            case 1:
                printf("Enter value to enqueue - ");
                if (scanf("%d", &val) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }

                q_enq(&q, val);
                break;
            case 2:
                val = q_deq(&q);
                printf("Dequeued value is %d\n", val);
                break;
            case 3:
                printf("Values in queue:\n");
                q_read(&q);
                break;
            default:
                break;
            }
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        }
    }
}