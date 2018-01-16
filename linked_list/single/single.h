#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

extern int invalid_ops;

void wrong_choice();
struct node *create_list(int, struct node*);
struct node *add(int, struct node*);
void   display(struct node*);
void   search(struct node*, int data);
struct node *memory_allocator(void);
void   memory_deallocator(struct node*);
struct node *addatbeg(int, struct node*);
struct node *addatpos(int, struct node*);
struct node *addafter(int, struct node*);
struct node *addbefore(int, struct node*);
struct node *addatend(int, struct node*);
struct node *delete(int, struct node*);
struct node *deleteatpos(int, struct node*);
struct node *deletebefore(int, struct node*);
struct node *deleteafter(int, struct node*);
struct node *reverse(struct node*);

struct node {
        int info;
        struct node *next;
};

