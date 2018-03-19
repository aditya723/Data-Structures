#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int TOS = -1;
int array[MAX];

int Isfull()
{
        if(TOS==MAX-1)
                return 1;
        else 
                return 0;
}
int Isempty()
{
        if(TOS==-1)
                return 1;
        else 
                return 0;
}	
void push(data)
{
        if(Isfull())
        {
                printf("\nfatal error: stack overflow\n\n");
                return ;
        }
        ++TOS;
        array[TOS]=data;
        return ;//to avoid warnings

}
int pop()
{
        if(Isempty())
        {
                printf("\nfatal error: stack underflow\n\n");
                return -1;
        }

        return array[TOS--];
}
int peek() 			
{
        if(Isempty())
        {
                printf("\nfatal error: stack underflow\n\n");
                return -1;
        }
        return array[TOS];
}
void display()
{
        int top = TOS;
        if(Isempty())
        {
                printf("\nfatal error: stack underflow\n\n");
                return;
        }

        while(top>=0)
                printf("%d ",array[top--]);
        printf("\n");
}	

int main()
{
        int choice = -1,data;
        while(1)
        {
                printf("stack operations available are:\n");
                printf("1:push\n2:pop\n3:peek()\n4:display\n5:exit\n");
                printf("enter your choice: ");
                choice = -1;
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter data: ");
                                scanf("%d",&data);
                                push(data);
                                break;
                        case 2:
                                printf("\ndata popped is %d\n",pop());
                                break;
                        case 3:
                                printf("\ndata at the top is %d\n",peek());
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(1);
                        default :
                                printf("dear user please enter the correct data\n");
                }//end of switch
        }//end of while
        return 0;
}				
