/*
*   n’th node from the end of a Linked List
*
* Given a Linked List and a number n, write a function that returns the value at the n’th node from end of the Linked List.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void wrong_choice();
struct node *create_list(int, struct node*);
void   display(struct node*);
struct node *memory_allocator(void);
void   memory_deallocator(struct node*);
int invalid_ops;
int data_found;

struct node {
        int info;
        struct node *next;
};


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

/* recursive */
int get_Nthnode_from_end_recursive(struct node *ptr, int index)
{
        if (ptr == NULL) {
                return index;
        }
        index = get_Nthnode_from_end_recursive(ptr->next, index);

        if (!(--index)) {
                printf("Node at index is: %d\n", ptr->info);
                data_found = 1;
                return index;
        }
        return index;
}

void get_Nthnode_from_end(struct node *ptr, int index)
{
        struct node *tmp = ptr;

        if (index < 0) {
                printf("Invalid index: %d\n", index);
                return;
        }
        while(ptr) {
                if (--index < 0)
                        tmp = tmp->next;
                ptr = ptr->next;
        }

        if (index <= 0)
                printf("Data is: %d\n", tmp->info);
        else
                printf("Invalid index\n");
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
                                "\t3. Get nth node from end\n"
                                "\t4. Get nth node from end(recursive)\n"
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
                                get_Nthnode_from_end(root, data);
                                break;
                        case 4:
                                printf("Enter index: ");
                                scanf(" %d", &data);
                                get_Nthnode_from_end_recursive(root, data);
                                if (!data_found)
                                        printf("Invalid index: %d\n", data);
                                data_found = 0;
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
