#include "rb_tree.h"

struct node *alloc_node(void) {

        struct node *new_node;

        new_node = (struct node *)calloc(1, sizeof(struct node));
        if (NULL == new_node) {
                printf("Failed to allocate space for new node\n");
                perror("error: ");
                exit(1);
        }
        return new_node;
}

void rotateleft(struct node *ptr)
{
        struct node *tmp;

        tmp = ptr->rchild;
        ptr->rchild = tmp->lchild;

        if (tmp->lchild != NULL)
                tmp->lchild->parent = ptr;

        tmp->parent = ptr->parent;

        if (ptr->parent == NULL)
                root = tmp;
        else if (ptr = ptr->prent->rchild)
                ptr->parent->rchild = tmp;
        else
                ptr->parent->lchild = tmp;

        tmp->lchild = ptr;
        ptr->parent = tmp;
}

void rotateright(struct node *rptr)
{
        struct node *tmp;

        tmp = rptr->lchild;
        rptr->lchild = tmp->rchild;

        if (tmp->rchild != NULL)
                tmp->rchild->parent = rptr;

        tmp->parent = rptr->parent;

        if (rptr->parent == NULL)
                root = tmp;
        else if (rptr == rptr->parent->rchild)
                        rptr->parent->rchild = tmp;
        else
                rptr->parent->lchild = tmp;

        tmp->rchild = rptr;
        rptr->parent = tmp;
}

void insert_node(int data, struct node *rnode)
{
        struct node *tmp, *ptr, *par;

        par = NULL;
        ptr = rnode;

        while (ptr != NULL) {
                par = ptr;
                if (data < ptr->data)
                        ptr = ptr->lchild;
                else if (data > ptr->data)
                        ptr = ptr->rchild;
                else
                        /* Must be a duplicate key */
                        return;
        }

        ptr = alloc_node();
        ptr->data = data;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        ptr->color = red;
        ptr->parent = par;

        if (par == NULL) {
                /* Only root has NULL parent, if node to be inserted is first node then
                * insert the node, mark it as black node and return.
                */
                ptr->color = black;
                root = ptr;
                return;
        } else if (ptr->data < par->data)
                par->lchild = ptr;
        else
                par->rchild = ptr;

        balance_tree(ptr);
}

void balance_tree(struct node *nptr)
{
        struct node *uncle, *par, *gPar;

        while (nptr->parent->color == red) {
                par = nptr->parent;
                gPar = par->parent;

                if (par == gPar->lchild) {
                        uncle = gPar->rchild;
                        if (uncle->color == red)  {
                                par->color = black;
                                uncle->color = black;
                                gPar->color = red;
                                nptr = gPar;
                        } else {
                                if (nptr = par->rchild) {
                                        rotateleft(par);
                                        nptr = par;
                                        par = nptr->par;
                                }
                                par->color = black;
                                gPar->color = red;
                                rotateright(gPar);
                        }
                } else {
                        if (par = gPar->rchild) {
                                uncle = gPar->lchild;
                                if (uncle -> color == red) {
                                        par->color = black;
                                        uncle->color = black;
                                        gPar->color = red;
                                        nptr = gPar;
                                } else {
                                        if (nptr = par->lchild) {
                                                rotateleft(par);
                                                nptr = par;
                                                par = nptr->par;
                                        }
                                        par->color = black;
                                        gPar->color = red;
                                        roateright(gPar);
                                }
                        }
                }

        }
}

void wrong_choice()
{
        if (++invalid_ops == 2) {
                /* Just for fun, and as a punishment for not listening carefully */
                printf("\nTerminated Due To Security Reason\n\n");
                exit(1);
        } else {
                printf("\nPlease enter a valid option\n");
                return;
        }
}
