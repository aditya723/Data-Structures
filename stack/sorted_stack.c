/*
* Given a stack, sort it using recursion. Use of any loop constructs like while, for..etc is not allowed.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 7

int price[MAX];

struct stack {
        int top;
        int array[MAX];
};


int Isfull(struct stack *s)
{
        if(s->top == MAX-1)
                return 1;
        else 
                return 0;
}
int Isempty(struct stack *s)
{
        if(s->top == -1)
                return 1;
        else 
                return 0;
}	
void push(struct stack *s, int data)
{
        if(Isfull(s))
        {
                printf("\nfatal error: stack overflow\n\n");
                return ;
        }
        ++s->top;
        s->array[s->top] = data;

        return;

}
int pop(struct stack *s)
{
        if(Isempty(s))
        {
                printf("\nfatal error: stack underflow\n\n");
                return -1;
        }

        return s->array[s->top--];
}
int peek(struct stack *s) 			
{
        if(Isempty(s))
        {
                printf("\nfatal error: stack underflow\n\n");
                return -1;
        }
        return s->array[s->top];
}

void display(struct stack *s)
{
        int top = s->top;

        if(Isempty(s))
        {
                printf("\nfatal error: stack underflow\n\n");
                return;
        }

        while(top>=0)
                printf("%d ",s->array[top--]);
        printf("\n");
}	

void sorted_insert(struct stack *s, int data)
{
        int temp;

        if (Isempty(s) || data > peek(s)) {
                push(s, data);
        } else {
                temp = pop(s);
                sorted_insert(s, data);
                push(s, temp);
        }
}

void sorted_stack(struct stack *s)
{
        int data;

        if (!Isempty(s)) {
                data = pop(s);
                sorted_stack(s);;
                sorted_insert(s, data);
        }
}

int main()
{
        int choice = -1,data;
        struct stack s;

        /* Make top of stack as -1 */
        s.top = -1;

        /* Get the stack elements */
        printf("Enter %d elements\n", MAX);
        for(int i = 0; i < MAX; i++) {
                scanf(" %d", &data);
                push(&s, data);
        }

        printf("main(): Before sorting ");
        display(&s);
        sorted_stack(&s);
        printf("main(): Atfer sorting ");
        display(&s);
        return 0;
}				
