#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void wrong_choice();
struct node *alloc_node(void);
struct node *insert_node(int, struct node *);
void inorder_traversal(struct node *);
void preorder_traversal(void);
void postorder_traversal(void);
void balance_tree(struct node *);
void rotateleft(struct node *);
void rotateright(struct node *);
void search_data(void);
void max_data(void);
void min_data(void);
void delete(void);
void delete_leaf(struct node *par, struct node *delnode);
void delete_node_has_one_child(struct node *par, struct node *delnode);
void delete_node_has_both_child(struct node *par, struct node *delnode);

int invalid_ops;
uint64_t MAX;

struct node {
        int data;
        enum {black, red} color;
        struct node *lchild;
        struct node *rchild;
        struct node *parent;
};

