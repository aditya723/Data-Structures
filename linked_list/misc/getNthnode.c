/*
*   get Nth node in a Linked List.
*
*   function that takes a linked list and an integer index and returns the data value stored in the node at that index position.
*
*   Input:  1->10->30->14,  index = 2
*   Output: 30  
*   The node at index 2 is 30
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

extern int invalid_ops;

void wrong_choice();
struct node *create_list(int, struct node*);
void   display(struct node*);
struct node *memory_allocator(void);
void   memory_deallocator(struct node*);

struct node {
        int info;
        struct node *next;
};

int invalid_ops;

void wrong_choice()
{
        if (++invalid_ops == 2) {
                /* Just for fun, and as a punishment for not listening carefully */
                printf("\nTerminated Due To Security Reason\n\n");
                exit(1);
        } else {
                printf("\nPlease choose a valid option...\n");
                return;
        }
}

int list_empty(struct node *tmp)
{
        if (NULL == tmp) {
                printf("List is empty\n");
                return 1;
        }
        return 0;

}

struct node *memory_allocator()
{
        struct node *tmp;

        if (NULL == (tmp = (struct node *)calloc(1, sizeof(struct node)))) {
                perror("Failed to allocate memory: ");
                exit(1);
        }
        return tmp;
}

struct node* create_list(int data, struct node* ptr)
{
        struct node *tmp = ptr;

        if (NULL == ptr) {
                ptr = memory_allocator();
                ptr->info = data;
                ptr->next = NULL;
                return ptr;
        }
        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = memory_allocator();
        tmp->next->info = data;
        tmp->next->next = NULL;

        return ptr;
}

void display(struct node *ptr)
{
        bool isempty = true;

        printf("List: ");

        while (ptr) {
                if (isempty)
                        isempty = false;

                printf("%d ", ptr->info);
                ptr = ptr->next;
        }
        if (isempty)
                printf("\b\b Empty...");
   
        printf("\n");
}

void getNthnode(struct node *ptr, int index)
{
        static int count = 0;

        if (ptr == NULL) {
                printf("Data not Found may be invalid index\n");
                return;
        }
        if (index == count)
                printf("Node at index is: %d\n", ptr->info);
        else getNthnode(ptr->next, --index);
}


int main(int argc, const char *argv[])
{
        int choice, data;
        struct node *root;

        do {
                printf("\n===========================================\n"
                        "Operations supported by single linked list:\n"
                        "============================================\n"
                                "\t0. Quit\n"
                                "\t1. Create List\n"
                                "\t2. Display\n"
                                "\t3. Get nth node\n"
                                "\nPlease select your choice of operation: ");
                choice = 4;
                scanf(" %d", &choice);
                getchar();

                switch (choice) {
                        case 0:
                                printf("bye...\n");
                                exit(0);
                        case 1:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = create_list(data, root);
                                break;
                        case 2:
                                display(root);
                                break;
                        case 3:
                                printf("Enter index: ");
                                scanf(" %d", &data);
                               getNthnode(root, data); 
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
