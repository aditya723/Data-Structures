#include "single.h"

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
                                "\t3.  Add at beginning\n"
                                "\t4.  Add at end\n"
                                "\t5.  Add after node\n"
                                "\t6.  Add before node\n"
                                "\t7.  Add at position\n"
                                "\t8.  Delete\n"
                                "\t9.  Delete after node\n"
                                "\t10. Delete before node\n"
                                "\t11. Delete at position\n"
                                "\t12. Delete at end\n"
                                "\t13. Delete at beg\n"
                                "\t13. Reverse\n"
                                "\t14. Search\n"
                                "Please select any operation:");
                scanf(" %d", &choice);
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
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = addatbeg(data, root);
                                break;
                        case 4:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = addatend(data, root);
                                break;
                        case 5:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = addafter(data, root);
                                break;
                        case 6:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = addbefore(data, root);
                                break;
                        case 7:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = addatpos(data, root);
                                break;
                        case 8:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = delete(data, root);
                                break;
                        case 9:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = deleteafter(data, root);
                                break;
                        case 10:
                                printf("Enter data: ");
                                scanf(" %d", &data);
                                root = deletebefore(data, root);
                                break;
                        case 11:
                                root = deleteatpos(root);
                                break;
                        case 12:
                                root = deleteatend(root);
                                break;
                        case 13:
                                root = deleteatbeg(root);
                                break;
                        case 14:
                                root = reverse(root);
                                break;
                        case 15:
                                printf("Enter data to be searched:\n");
                                scanf(" %d", &data);
                                search(root, data);
                                break;
                        default:
                                wrong_choice();
                                break;
                }
        } while (1);
}
