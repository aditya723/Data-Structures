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

/* Algorithm to calculate stock span problem starts here */
void calculate_spane(int price[], int size)
{
        struct stack s;
        int span[MAX];

        /* save index of day zero onto stack */
        s.top = -1;
        push(&s,0);

        /* stock span for day 1 must be 1 */
        span[0] = 1;
        
        /* span for other days */
        for(int i = 1; i < MAX; i++) { 
                /* while stack which stores index is not empty && stock price of current day is greater than stock price
                 * of peek index day stored onto stack, pop index from stack
                 */
                while (!Isempty(&s) && price[i] >= price[peek(&s)])
                        pop(&s);

                /* if stack has become empty, it means all previous days price are smaller than current day price
                *  so we will add 1 in stock span because we started this loop from i = 1.
                *  if stack is not empty, it means stock span lasts till the day stored on top of stack.
                */
                span[i] = Isempty(&s) ? i+1: i-peek(&s);

                /*Push the index onto the stack */
                push(&s,i);
        }

        /* Display stock span */
        printf("stock span: ");
        for(int i =0; i < MAX; i++)
                printf("%d ", span[i]);

        printf("\n");
}

int main()
{
        int choice = -1,data;

        /* Get the price of stock */
        printf("Enter %d elements\n", MAX);
        for(int i = 0; i < MAX; i++)
                scanf(" %d", &price[i]);

        calculate_spane(price, MAX);
        return 0;
}				
