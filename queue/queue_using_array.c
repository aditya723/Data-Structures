#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*Queue data structure */
struct queue{
        int front;
        int rear;
        int array[MAX];
};

void init(struct queue *s)
{
        s->front = -1;
        s->rear = -1;
}		

int Isempty(struct queue *s)
{
        /*A QUEUE is empty when either rear and front element of queue() is -1.
         * or we reached to a situation where front has crossed rear element.
         */
        return ((s->front==-1&&s->rear==-1)||(s->front==s->rear+1)) ? 1 : 0;
}

int Isfull(struct queue *s)
{
        /*Well, this is so obvious */
        return s->rear==MAX-1 ? 1 : 0;
}	 	

void enqueue(int data, struct queue *s)
{
        /* If queue is full it means it is an queue overflow case */
        if(Isfull(s))
        {
                printf("FATAL ERROR: queue overflow\n");
                return ;
                /* If it is the first element of array then update real and front */
        } else if(s->front==-1) {
                ++s->rear;
                ++s->front;
        } else 
                /* As element is added to rear index so update read index */
                ++s->rear;

        /* Add data to rear index of queue */
        s->array[s->rear] = data;
        return ;
}

int dequeue( struct queue *s)
{
        int data ;

        /* If queue is empty then it is a queue underflow case */
        if(Isempty(s))
        {
                printf("FATAL ERROR : queue underfllow\n");
                return -9999;
        }

        /* Retrieve the data from queue's front index
         * A queue is a FIFO(Fist in Fist Out) data structure.
         */
        data=s->array[s->front];

        /* Update front */
        ++s->front;

        return data;
}

void display(struct queue *s)
{
        int i;

        /* If queue is empty then nothing to display */
        if(Isempty(s))
        {
                printf("FATAL ERROR: Queue underflow\n");
                return ;
        }

        printf("queue elements are: ");
        /* Traverse the element of array until it become empty */
        for(i= s->front; i <= s->rear; ++i)
        {
                printf("%d ",s->array[i]);
        }
        printf("\n");
        return;
}							
int main()
{
        int data,choice, bad_choice = 0;
        struct queue *s;
        s = (struct queue*)malloc(sizeof(struct queue));
        init(s);

        while(1)
        {
                printf("\n1:enqueue\n2:dequeue\n3:display\n4:exit\n");
                printf("enter the choice: ");
                choice = -1;
                scanf(" %d",&choice);
                getchar();
                switch(choice)
                {
                        case 1 :
                                printf("enter  data: ");
                                scanf("%d",&data);
                                enqueue(data,s);
                                break;
                        case 2 :
                                printf("Data is: %d\n",dequeue(s));
                                break;
                        case 3 :
                                display(s);
                                break;
                        case 4 :
                                free(s);
                                exit(0);
                        default :
                                if(bad_choice) {
                                        printf("\nTo many bad choices [%d/5]\n", bad_choice);
                                        if (bad_choice == 5) {
                                                free(s);
                                                exit(1);
                                        }
                                } else
                                        printf("\nDear user please enter the valid input...\n");
                                bad_choice++;
                }//end of switch
        }//end of while
        return 0;
}//end of main	
