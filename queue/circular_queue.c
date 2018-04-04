#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct queue {
        int front;
        int rear;
        int cq[SIZE];
};

struct queue q = {.front = -1, .rear = -1, .cq[0] = -1};

/* Add data at rear position of queue */
void enqueue()
{
        int value;

        /* if front is zero and rear reached at last index then queue is full any further enqueue
         * is a overflow. Also if rear has reached to a index previous to front then queue is full
         * any further enqueue is a overflow.
         * if(q.front == (q.rear+1)%SIZE), a compact condition to detect queue overflow
         */
        if ((q.front == 0 && q.rear == SIZE - 1) || (q.rear == q.front - 1)) {
                printf("FATAL: Queue  overflow----> size of queue is: %d\n", SIZE);
                return ;
        } else {
                /*Enqueue if queue is not full */
                printf("Enter data: ");
                scanf("%d",&value);
                /* If front is -1 it means queue is empty and enqueuing has just begun so
                 * make rear same as front.
                 */
                if(q.front == -1)
                        q.front = q.rear = 0;
                else
                        /*
                         * Move rear to next position 
                         */
                        q.rear = (q.rear + 1)%SIZE;
                /* Add element to the queue */
                q.cq[q.rear] = value;
        }
}

/* Take a element out of queue */
int dequeue()
{
        int value;

        /* Check if queue is empty */
        if (q.front == -1) {
                printf("\nqueue is underflow\n");
                return -99999;
        } else {
                /* If queue is not empty then pick an element from front position
                * and adjust front.
                */
                value = q.cq[q.front];
                /*If front coincides with rear index then queue has become empty 
                * adjust rear and front as -1;
                */
                if(q.front == q.rear)
                        q.front = q.rear = -1;
                else
                /* shift front to next position , this is a million dollar statement
                * It plays a big role to make queue circular
                */
                        q.front = (q.front + 1)%SIZE;
        }
        return value;
}

/* Traverse queue */
void display()
{
        int i, size = SIZE - 1, size_adjusted = 0;

        /* Do not traverse a empty queue */
        if(q.front == -1) {
                printf("\nqueue is empty\n");
                return ;
        } else if (q.front <= q.rear) {
                /* Traverse until front is same as rear */
                printf("\nQueue elements:");
                for(i = q.front;i <= q.rear; i++)
                        printf(" %d", q.cq[i]);
        } else {
                /*If front is greater than rear then traverse till last index of queue
                * again traverse till the rear index of queue
                */
                printf("\nQueue elements:");
                for(i = q.front; i <= size; i++) {
                        printf(" %d", q.cq[i]);
                        if (!size_adjusted && i == size) {
                                i = -1;
                                size = q.rear;
                                size_adjusted = 1;
                        }
                }
        }
        printf("\n");
}

int main()
{
        int option, bad_choice = 0;

        while(1)
        {
                printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.exit\nChoose an option: ");
                option = -1;
                scanf(" %d",&option);
                getchar();
                switch(option)
                {
                        case 1:
                                enqueue();
                                break;
                        case 2:
                                printf("Dequeue element is: %d\n", dequeue());
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default:
                                if(bad_choice) {
                                        printf("\nTo many bad choices [%d/5]\n", bad_choice);
                                        if (bad_choice == 5) {
                                                exit(1);
                                        }
                                } else
                                        printf("\nDear user please enter the valid input...\n");
                                bad_choice++;
                }
        }
}									

