/*
* Merge two sorted linked lists
*
* Write a SortedMerge() function that takes two lists, each of which is sorted in increasing order, and merges the two
* together into one list which is in increasing order. SortedMerge() should return the new list. The new list should be made by splicing
* together the nodes of the first two lists.
*
* For example if the first linked list a is 5->10->15 and the other linked list b is 2->3->20, then SortedMerge() should return a pointer
* to the head node of the merged list 2->3->5->10->15->20.
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
struct node *SortedMerge(struct node *, struct node*);
void   display(struct node*);
struct node *memory_allocator(void);

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

struct node *recursive_merge(struct node *list1, struct node *list2)
{
                struct node *result;

                if (list1 == NULL) {
                        return list2;
                } else if (list2 == NULL) {
                        return list1;
                } else if (list1->info <= list2->info) {
                        result = list1;
                        result->next = recursive_merge(list1->next, list2);
                } else {
                        result = list2;
                        result->next = recursive_merge(list1, list2->next);
                }
                return result;
}

struct node *non_recursive_merge(struct node *list1, struct node *list2)
{
        struct node *final_list = memory_allocator();
        struct node *new_list = final_list;

        while (1) {
                if (list1 == NULL) {
                        new_list->next = list2;
                        return final_list->next;
                } else if (list2 == NULL) {
                        new_list->next = list1;
                        return final_list->next;
                } else if (list1->info <= list2->info) {
                        new_list->next = list1;
                        list1 = list1->next;
                        new_list = new_list->next;
                } else {
                        new_list->next = list2;
                        list2 = list2->next;
                        new_list = new_list->next;
                }
        }
}

struct node *SortedMerge(struct node *head1, struct node *head2)
{
        int size = 0;
        int data = 0;

        printf("Enter sorted list 1 size followed by data: ");
        scanf(" %d", &size);
        while (size--) {
                scanf(" %d", &data);
                head1 = create_list(data, head1);
        }

        size = 0;
        data = 0;
        printf("Enter sorted list 2 size followed by data: ");
        scanf(" %d", &size);
        while (size--) {
                scanf(" %d", &data);
                head2 = create_list(data, head2);
        }
        if (!head1 && !head2) {
                printf("List empty...\n");
                return NULL;
        }

        printf("Press 1 of recursive merging, 2 for non recursive merging: ");
        int choice = -1;
        do {
                choice = -1;
                scanf(" %d", &choice);
                switch (choice) {
                        case 1:
                                return recursive_merge(head1, head2);
                        case 2:
                                return non_recursive_merge(head1, head2);
                        default:
                                printf("Invalid choice\n");
                                printf("Press 1 of recursive merging, 2 for non recursive merging");
                                break;
                }
        } while (1);

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

int main(int argc, const char *argv[])
{
        int choice, data;
        struct node *root1 = NULL, *root2 = NULL, *merge_list = NULL;

        do {
                printf("\n===========================================\n"
                        "Operations supported by single linked list:\n"
                        "============================================\n"
                                "\t0. Quit\n"
                                "\t1. Merge sorted list\n"
                                "\t2. Display\n"
                                "\nPlease select your choice of operation: ");
                choice = 3;
                scanf(" %d", &choice);
                getchar();

                switch (choice) {
                        case 0:
                                printf("bye...\n");
                                exit(0);
                        case 1:
                                merge_list = SortedMerge(root1, root2);
                                break;
                        case 2:
                                display(merge_list);
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
