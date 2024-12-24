#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for(int i = 1; i < argc; i++) {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        if (list == NULL) {
            // Insert at the beginning if the list is empty
            list = n;
        } else if (n->number < list->number) {
            // Insert at the beginning
            n->next = list;
            list = n;
        } else {
            // Insert in the correct position
            node *ptr = list;
            while (ptr->next != NULL && n->number >= ptr->next->number) {
                ptr = ptr->next;
            }
            // Insert the new node
            n->next = ptr->next;
            ptr->next = n;
        }
    }

    // Print the sorted linked list
    node *ptr = list;
    while (ptr != NULL) {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }

    // Free the allocated memory
    while (list != NULL) {
        node *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
