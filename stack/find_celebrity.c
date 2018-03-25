#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Suppose we have 8 people in party */
#define PCOUNT 8

#if 0
bool person[PCOUNT][PCOUNT] = {
                        /*   p0 p1 p2 p3 p4 p5 p6 p7 */
                       /*p0*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p1*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p2*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p3*/{0, 0, 0, 0, 0, 0, 0, 0},
                       /*p4*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p5*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p6*/{0, 0, 0, 0, 0, 0, 1, 0},
                       /*p7*/{0, 0, 0, 0, 0, 0, 1, 0},
};
#else
bool person[PCOUNT][PCOUNT] = {
                        /*   p0 p1 p2 p3 */
                       /*p0*/{0, 0, 1, 0},
                       /*p1*/{0, 0, 1, 0},
                       /*p2*/{0, 0, 1, 0},
                       /*p3*/{0, 0, 0, 0},
};
#endif

struct stack {
        int top;
        int array[PCOUNT];
};


int Isfull(struct stack *s)
{
        if(s->top == PCOUNT-1)
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

bool do_i_know_you(int a, int b)
{
        return person[a][b];
}

/* Algorithm to find celebrity starts here */
void find_celebrity()
{
        struct stack s = {.top = -1};
        int c; // i am celebrity
        int p1, p2;
        int size;
        bool c_present = true;

        /* Push Every person onto stack */
        for(int i = 0; i < PCOUNT; i++)
                push(&s,i);

        p1 = peek(&s);
        pop(&s);
        p2 = peek(&s);
        pop(&s);

        size = PCOUNT - 2;

        while (size > 1) {
                if (do_i_know_you(p1, p2)) {
                        p1 = peek(&s);
                        pop(&s);
                } else {
                        p2 = peek(&s);
                        pop(&s);
                }
                --size;
        }

        /**/
        c = peek(&s);
        pop(&s);

        if (do_i_know_you(c, p2))
                c = p2;

        if (do_i_know_you(c, p1))
                c = p1;

        for (int i = 0; i<PCOUNT; i++) {
                if ((i != c) && (do_i_know_you(c, i) || (!do_i_know_you(i, c)))) {
                        c_present = false;
                        break;
                }
        }
        if (c_present)
                printf("%d is a celebrity\n", c);
        else
                printf("No celebrity in party\n");
}

int main()
{
        find_celebrity();
        return 0;
}				
