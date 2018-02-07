/*
* Swap nodes in a linked list without swapping data
*
* Input:  10->15->12->13->20->14,  x = 12, y = 20
* Output: 10->15->20->13->12->14
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

struct node *swap(struct node *ptr)
{
        struct node *node1 = NULL, *node2 = NULL, *tmp, *dummy;
        struct node *prev1 = NULL, *prev2 = NULL, *prev = NULL;
        int data1, data2;

        printf("Enter nodes to be swapped\n");
        printf("node1: ");;
        scanf(" %d", &data1);
        printf("\nnode2: ");;
        scanf(" %d", &data2);

        if (data1 == data2) {
                printf("Both data are same");
                return ptr;
        }

        tmp = ptr;
        while (tmp) {
                if (tmp->info == data1) {
                        node1 = tmp;
                        prev1 = prev;
                }
                if (tmp->info == data2) {
                        node2 = tmp;
                        prev2 = prev;
                }
                prev = tmp;
                tmp = tmp->next;
        }

        if (!node1 || !node2) {
                printf("Incorrect swap request\n");
                return ptr;
        }


        /*If data1 is not the head of list*/
        if (prev1)
                prev1->next = node2;
        else /* data2 will be head of list */
                ptr = node2;

        /*If data2 is not the head of list*/
        if (prev2)
                prev2->next = node1;
        else /* data1 will be head of list */
                ptr = node1;

        /*Swap pointers*/
        dummy = node2->next;
        node2->next = node1->next;
        node1->next = dummy;

        return ptr;
}

int main(int argc, const char *argv[])
{
        int choice, data;
        struct node *root;

        do {
                printf("\n===========================================\n"
                        "Operations supported by single linked list:\n"
                        "============================================\n"
                                "\t0.  Quit\n"
                                "\t1.  Create List\n"
                                "\t2.  Display\n"
                                "\t3. Swap node without swapping data\n"
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
                                root = swap(root);
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
