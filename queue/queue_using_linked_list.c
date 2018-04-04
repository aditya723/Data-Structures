#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
        int data ;
        struct node *next;
}; 

struct node *front= NULL;
struct node *rear = NULL;	

/* Add data at beginning of queue */
void enqueue(int data)
{
        struct node *temp;

        temp =(struct node*)malloc(sizeof(struct node));

        temp->data=data;
        temp->next=NULL;

        /* If queue is empty then add data to queue and make front and rear as same */
        if(front==NULL)
        {
                front=temp;
                rear=temp;
                return;
        }

        /* If queue is not empty then add data to rear position */
        rear->next=temp;
        rear=temp;

        return;

}
int dequeue()
{
        int data;
        struct node *temp;

        temp =(struct node*)malloc(sizeof(struct node));

        if(front==NULL)
        {
                printf("FATAL ERROR: Queue Underflow\n");
                return -99999; 
        }	 

        /*Dequeue front node and shift front node to next node */
        temp=front;
        data=temp->data;
        front=temp->next;
        free(temp);

        return data;
}	

void display()
{
        struct node *temp = front;

        if (!temp) {
                printf("FATAL ERROR: Queue Underflow\n");
                return;
        }

        printf("Queue elements are: ");

        /* Display until queue becomes empty */
        while (temp) {
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("\n");
}


int main()
{
        int data,choice, bad_choice = 0;

        while(1) {

                printf("\n1: enqueue\n2: dequeue\n3: Display\n4: exit\nEnter a valid choice: ");
                choice = -1;
                scanf("%d",&choice);
                getchar();

                switch(choice) {
                        case 1:
                                printf("Enter element: ");
                                scanf("%d",&data);
                                enqueue(data);
                                break;
                        case 2:
                                printf("dequeue element is: %d\n",dequeue());
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default :
                                if(bad_choice) {
                                        printf("\nTo many bad choices [%d/5]\n", bad_choice);
                                        if (bad_choice == 5)
                                                exit(1);
                                } else
                                        printf("\nDear user please enter the valid input...\n");

                                bad_choice++;
                }
        }
        return 0;
}		
