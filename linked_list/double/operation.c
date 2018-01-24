#include "single.h"

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

struct node *add(int data, struct node *ptr)
{
        struct node *tmp = ptr;

        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = memory_allocator();
        tmp->next->info = data;
        tmp->next->next = NULL;
        tmp->next->prev = tmp;

        return ptr;
}

struct node *addatend(int data, struct node *ptr)
{
        struct node *tmp;

        if (NULL == ptr) {
                ptr = memory_allocator();
                ptr->info = data;
                ptr->next = NULL;
                ptr->prev = NULL;
                return ptr;
        }

        return add(data, ptr);
}

struct node* create_list(int data, struct node* ptr)
{
        struct node *tmp;

        if (NULL == ptr) {
                ptr = memory_allocator();
                ptr->info = data;
                ptr->next = NULL;
                ptr->prev = NULL;
                return ptr;
        }

        return add(data, ptr);
}

void display(struct node *ptr)
{
        bool isempty = true;

        printf("list is: ");

        while (ptr) {
                if (isempty)
                        isempty = false;

                printf("%d ", ptr->info);
                ptr = ptr->next;
        }
        if (isempty)
                printf("empty");
        
        printf("\n");
}

void search(struct node *ptr, int data)
{
        int pos = 0;

        if (list_empty(ptr))
                return;

        while (ptr && ptr->info == data) {
                ptr = ptr->next;
                ++pos;
        }

        if (ptr)
                printf("Data not found\n");
        else
                printf("Data found at %d position\n", pos);

        return;
}
struct node *addatbeg(int data, struct node *ptr)
{
        struct node *tmp;

        if (NULL == ptr) {
                tmp = memory_allocator();
                tmp->next = NULL;
                tmp->prev = NULL;
                tmp->info = data;
        } else {
                tmp = memory_allocator();
                tmp->next = ptr;
                tmp->next->prev = tmp;
                tmp->prev = NULL;
                tmp->info = data;
        }
        return tmp;
}


struct node *addbefore(int data, struct node *ptr)
{
        struct node *tmp = ptr;
        struct node *tmp1, *prev = NULL;

        if (list_empty(ptr))
                return ptr;

        while (tmp && data != tmp->info) {
                prev = tmp;
                tmp = tmp->next;
        }

        if (!tmp) {
                printf("Information provided is incorrect,"
                        " may be data is not in list\n");
                return ptr;
        }
        tmp1 = memory_allocator();
        if (NULL == prev) {
                tmp1->next = ptr;
                tmp1->prev = NULL;
                ptr->prev = tmp1;
                tmp1->info = data;
                return tmp1;
        }

        prev->next = tmp1;
        tmp1->prev = prev;
        tmp1->info = data;
        tmp1->next = tmp;
        tmp->prev = tmp1;
        return ptr;
}

struct node *addafter(int data, struct node *ptr)
{
        struct node *tmp = ptr;
        struct node *tmp1, *prev = NULL;
        int item;

        printf("After which data in list:\n");
        scanf("%d", &item);

        if (list_empty(ptr))
                return ptr;

        while (tmp && item != tmp->info) {
                prev = tmp;
                tmp = tmp->next;
        }

        if (!tmp) {
                printf("Information provided is incorrect,"
                        " may be data is not in list\n");
                return ptr;
        }
        tmp1 = memory_allocator();
        tmp1->next = tmp->next;
        tmp1->prev = tmp;
        tmp1->info = data;
        tmp->next = tmp1;

        if (tmp->next)
                tmp->next->prev = tmp1;

        return ptr;
}

struct node *addatpos(int data, struct node *ptr)
{
        int pos;
        struct node *tmp = ptr;
        struct node *new;

        if (list_empty(ptr))
                return ptr;

        printf("Enter position\n");
        scanf("%d", &pos);

        if (0 == pos)
                return addatbeg(data, ptr); 

        while (tmp && --pos)
                tmp = tmp->next;

        if (pos != 0) {
                printf("List is smaller\n");
                return ptr;
        }

        new = memory_allocator();
        new->info = data;
        new->next = tmp->next;
        new->prev = tmp;
        tmp->next = new;

        if (tmp->next)
                tmp->next->prev = new;

        return ptr;
}

void memory_deallocator(struct node *junk)
{
        junk->next = NULL;
        junk->info = 0;
        free(junk);
        junk = NULL;
}

struct node *delete(int data, struct node *ptr)
{
        struct node *tmp = ptr;
        struct node *prev = NULL;

        if (list_empty(ptr))
                return ptr;

        while (tmp && tmp->info != data) {
                prev = tmp;
                tmp = tmp->next;
        }

        if (!tmp) {
                printf("Data :%d not found in list\n", data);
                return ptr;
        }

        if (NULL == prev) {
               ptr = ptr->next;

               if (ptr)
                        ptr->prev = NULL;

               memory_deallocator(tmp);
               return ptr;
        }

        prev->next = tmp->next;
        if (tmp->next) {
                tmp->next->prev = prev;
        }

        memory_deallocator(tmp);

        return ptr;
}

struct node *deleteafter(int data, struct node *ptr)
{
        struct node *tmp = ptr;
        struct node *junk;

        if (list_empty(ptr))
                return ptr;
        
        while (tmp && tmp->info != data)
                tmp = tmp->next;

        if (tmp) {
                if (tmp->next) {
                        junk = tmp->next;
                        tmp->next = tmp->next->next;

                        if (tmp->next)
                                tmp->next->prev = tmp;

                        memory_deallocator(junk);
                } else {
                        printf("No after data in the list");
                }
        } else {
                printf("Invalid request: data provided was incorrect\n");
        }
        return ptr;
}

struct node *deletebefore(int data, struct node *ptr)
{
        struct node *tmp = ptr;
        struct node *junk = NULL;

        if (list_empty(ptr))
                return ptr;
        
        while (tmp && tmp->info != data)
                tmp = tmp->next;

        if (!tmp) {
                printf("Data not found\n");
                return ptr;
        }

        if (!tmp->prev) {
                printf("No before node\n");
                return ptr;
        }

        junk = tmp->prev;
        tmp->prev = tmp->prev->prev;

        if (tmp->prev)
                tmp->prev->next = tmp;

        memory_deallocator(junk);

        if (tmp->prev)
                return ptr;

        return tmp;
}

struct node *deleteatbeg(struct node *ptr)
{
        struct node *junk = NULL;

        if (list_empty(ptr))
                return ptr;

        junk = ptr;
        ptr = ptr->next;

        memory_deallocator(junk);
        return ptr;
}

struct node *deleteatend(struct node *ptr)
{
        struct node *tmp = ptr;

        if (list_empty(ptr))
                return ptr;

        while (tmp->next)
                tmp = tmp->next;
        
        if (tmp->prev)
                tmp->prev->next = NULL;
        else
                ptr = NULL;
        
        memory_deallocator(tmp);
        return ptr;
}

struct node *deleteatpos(struct node *ptr)
{
        struct node *tmp = ptr;
        int pos;
        
        if (list_empty(ptr))
                return ptr;

        printf("Enter position\n");
        scanf("%d", &pos);

        if (0 == pos)
                return deleteatbeg(ptr);

        while (tmp && pos--)
                tmp = tmp->next;
        
        if (-1 != pos) {
                printf("List is smaller\n");
                return ptr;
        }

        tmp->prev->next = tmp->next;

        if (tmp->next)
                tmp->next->prev = tmp->prev;

        memory_deallocator(tmp);

        return ptr;
}

struct node *reverse(struct node *ptr)
{
        struct node *tmp, *nroot, *oroot;

        if (list_empty(ptr))
                return ptr;

        tmp = ptr;
        oroot = NULL;

        while (tmp) {
                nroot = tmp->next;
                tmp->next = oroot;
                oroot = tmp;
                tmp = nroot;
        }
        ptr = oroot;
        return ptr;
}
