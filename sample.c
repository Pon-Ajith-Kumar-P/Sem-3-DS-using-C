#include <stdio.h>
#define M 10 // Hash table size

// Global variables
int ht[M], found = 0, key;

// Hash function to calculate index
int h(int x) {
    return x % M;
}

void insert_val(int val) {
    int index, i;
    index = h(val);

    for (i = 0; i < M; i++) {
        int probe = (index + i) % M; // Linear probing
        if (ht[probe] == -1) {
            ht[probe] = val;
            printf("\nValue %d inserted at position %d\n", val, probe);
            return;
        }
    }

    printf("\nHash table is full. Cannot insert value %d.\n", val);
}

void search_val(int val) {
    int index, i;
    index = h(val);

    for (i = 0; i < M; i++) {
        int probe = (index + i) % M; // Linear probing
        if (ht[probe] == val) {
            printf("\nValue %d found at position %d\n", val, probe);
            found = 1;
            key = probe;
            return;
        }
        if (ht[probe] == -1) break; // Stop searching if an empty slot is encountered
    }

    printf("\nValue %d not found in the hash table.\n", val);
    found = 0;
    key = -1;
}

void delete_val(int val) {
    search_val(val);
    if (found == 1 && key != -1) {
        printf("\nValue %d deleted from position %d\n", ht[key], key);
        ht[key] = -1;
    } else {
        printf("\nDeletion failed. Value not found.\n");
    }
}

void display() {
    printf("\nHash table contents:\n");
    for (int i = 0; i < M; i++) {
        if (ht[i] == -1)
            printf("[%d]: EMPTY\n", i);
        else
            printf("[%d]: %d\n", i, ht[i]);
    }
}

int main() {
    int option, val;

    // Initialize the hash table with -1
    for (int i = 0; i < M; i++)
        ht[i] = -1;

    do {
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &val);
                insert_val(val);
                break;
            case 2:
                printf("\nEnter the element to be searched: ");
                scanf("%d", &val);
                search_val(val);
                break;
            case 3:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &val);
                delete_val(val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (option != 5);

    return 0;
}
