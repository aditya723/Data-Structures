#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int histogram[MAX];

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

int max_reactangle_in_histogram(int histogram[], int size_of_histogram)
{
        /*Create a stack so that we can push histogram indices onto it*/
        struct stack s = {.top = -1};
        int max_area = 0, cur_area = 0, cur_top;
        int area = 0, i = 0;

        /* Keep traversing histogram until each index in iterated */
        while (i < size_of_histogram) {
                /*Idea is to push histogram index onto stack only if stack is empty or
                * element at index = top_of_stack in histogram is less than element at current
                * index in histogram.
                * We did so because if current element in histogram is greater than peek index
                * element then it means elements at index stored onto stack will be contained in
                * current element.
                */
                if (Isempty(&s) || histogram[i] >= histogram[peek(&s)]) {
                        push(&s, i);
                        i++;
                } else {
                /* If above condition is not met then if mean previous element is not contained in
                * current index element.
                * In this case we will pop out current index and calculate the area until stack has become
                * empty or we reach to a index whose value is less than or equal to current index value.
                */
                        cur_top = pop(&s);
                /*
                * To  calculate cur_area multiply element corresponding to current top of stack
                * with previous common elements i.e. for a histogram 1,2,3,4,5,3. when we reach
                * here for extreme right element 3 then cur_area should be 5, and later 4
                * of course, max area should be 5 here.
                */
                        cur_area = histogram[cur_top] * (Isempty(&s) ? i-1: i - peek(&s) -1);
                /* if current rectangular area is greater the max area calculated so far then
                * we will consider updating max area.
                */
                        if (cur_area > max_area)
                                max_area = cur_area;
                }
        }
        /* Calculate the area for remaining elements left on stack */
        while (!Isempty(&s)) {
                cur_top = pop(&s);
                cur_area = histogram[cur_top] * (Isempty(&s) ? i-1: i - peek(&s) -1);
                if (cur_area > max_area)
                        max_area = cur_area;

        }
        /* Finally return max area.
        * aaahh...
        **/
        return max_area;
}

int main()
{
        /* Get the histogram */
        printf("Enter %d elements\n", MAX);
        for(int i = 0; i < MAX; i++)
                scanf(" %d", &histogram[i]);

        printf("Max rectangular area: %d\n", max_reactangle_in_histogram(histogram, MAX));
        return 0;
}				
