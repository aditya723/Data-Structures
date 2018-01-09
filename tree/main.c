/*#######################################################################
*
* main.c
*
*
*#######################################################################*/

#include "rb_tree.h"

struct node *root = NULL;

int main(int argc, const char *argv[])
{
        int op, data;

        do {
                printf("\nList of Operations supported: \n"
                                "0. Create\n"
                                "1. Insert a new data\n"
                                "2. Search a data\n"
                                "3. Node with max\n"
                                "4. Node with min\n"
                                "5. Deletion\n"
                                "6. Pre-order traversal\n"
                                "7. In-order traversal\n"
                                "8. Post order traversal\n"
                                "9. Height of tree\n"
                                "10. Quit\n"
                                "\nPlease Enter you choice: ");
                scanf("%d", &op);

                switch (op) {
                        case 1:
                                printf("Enter data: ");
                                scanf("%d", &data);
                                insert_node(data, root);
                                break;
                        case 2:
                                search_data();
                                break;
                        case 3:
                                max_data();
                                break;
                        case 4:
                                min_data();
                                break;
                        case 5:
                                delete();
                                break;
                        case 6:
                                preorder_traversal();
                                break;
                        case 7:
                                inorder_traversal(root);
                                break;
                        case 8:
                                // postprder_traversal();
                                break;
                        case 9:
                                // height();
                                break;
                        case 10:
                                printf("bye...\n");
                                exit(0);
                        default:
                                wrong_choice();
                }
        } while (1);
}
