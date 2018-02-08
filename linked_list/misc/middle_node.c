/*
* Find the middle of a given linked list
*
* Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3.
*
* If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked
* list is 1->2->3->4->5->6 then output should be 4.
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

struct node *mid_node_2ptr(struct node *ptr)
{
        struct node *tmp, *mid;

        if (!ptr) {
                printf("List empty\n");
                return ptr;
        }

        mid = ptr;
        tmp = ptr;
        while (tmp && tmp->next) {
                tmp = tmp->next->next;
                mid = mid->next;
        }

        printf("Mid: %d\n", mid->info);

        return ptr;
}

void mid_node_1ptr(struct node *ptr)
{
        struct node *mid;
        int count = 0;

        if (!ptr) {
                printf("List empty\n");
                return;
        }

        mid = ptr;
        while (ptr) {
                /* Update the middle pointer for even nodes only */
                if (count & 1)
                        mid = mid->next;
                ptr = ptr->next;
        }

        printf("Mid: %d\n", mid->info);

        return;
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
                                "\t3. Middle node(2 pointers)\n"
                                "\t4. Middle node(1 pointers)\n"
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
                                root = mid_node_2ptr(root);
                                break;
                        case 4:
                                mid_node_1ptr(root);
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
