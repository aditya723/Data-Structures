/*
* Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc,
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

        return ;//to avoid warnings

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

/* Recursion starts here */
void revrse_recursion(struct stack *s)
{
        int data;

        if (!Isempty(s)) {
                data = pop(s);
                revrse_recursion(s);
                push(s, data);
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

        printf("main(): Before recursion ");
        display(&s);
        revrse_recursion(&s);
        printf("main(): Before recursion ");
        display(&s);
        return 0;
}				
