#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for each node in the heap
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

// Function to create a new node
node* createNode(int value, node* parent) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

// Function to swap the values of two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up after insertion
void heapifyUp(node* node) {
    while (node->parent != NULL && node->parent->value < node->value) {
        swap(&node->value, &node->parent->value);
        node = node->parent;
    }
}

// Function to insert a new value into the heap
node* insertNode(node* root, int value, int* count) {
    (*count)++;
    node* newNode = NULL;

    if (root == NULL) {
        return createNode(value, NULL);
    }

    // Find the insertion point using level order traversal
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        node* current = queue[front++];

        if (current->left == NULL) {
            current->left = createNode(value, current);
            newNode = current->left;
            break;
        } else {
            queue[rear++] = current->left;
        }

        if (current->right == NULL) {
            current->right = createNode(value, current);
            newNode = current->right;
            break;
        } else {
            queue[rear++] = current->right;
        }
    }

    heapifyUp(newNode);
    return root;
}

// Function to get the last node in the heap for deletion
node* getLastNode(node* root, int count) {
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int targetIndex = count - 1;
    int index = 0;

    while (front < rear) {
        node* current = queue[front++];

        if (index == targetIndex) {
            return current;
        }
        index++;

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    return NULL;
}

// Function to heapify down after deletion
void heapifyDown(node* node) {
    while (node != NULL) {
        node* largest = node;
        if (node->left != NULL && node->left->value > largest->value) {
            largest = node->left;
        }
        if (node->right != NULL && node->right->value > largest->value) {
            largest = node->right;
        }
        if (largest != node) {
            swap(&node->value, &largest->value);
            node = largest;
        } else {
            break;
        }
    }
}

// Function to delete the max value (root) from the heap
int deleteMax(node** root, int* count) {
    if (*root == NULL || *count == 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int maxValue = (*root)->value;
    node* lastNode = getLastNode(*root, *count);

    if (lastNode == *root) {
        free(*root);
        *root = NULL;
    } else {
        (*root)->value = lastNode->value;
        if (lastNode->parent->left == lastNode) {
            lastNode->parent->left = NULL;
        } else {
            lastNode->parent->right = NULL;
        }
        free(lastNode);
        heapifyDown(*root);
    }

    (*count)--;
    return maxValue;
}

// Function to convert the heap to an array
void heapToArray(node* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    arr[(*index)++] = root->value;
    heapToArray(root->left, arr, index);
    heapToArray(root->right, arr, index);
}

// Function to print the heap as a tree
void printHeapTreeView(int a[], int n) {
    int height = (int)log2(n) + 1;

    printf("\nThe max heap tree view with spaces is:\n");
    for (int level = 0; level < height; level++) {
        int levelStart = pow(2, level) - 1;
        int levelEnd = pow(2, level + 1) - 1;
        int space = pow(2, height - level) - 1;

        // Print leading spaces
        for (int i = 0; i < space / 2; i++) {
            printf(" ");
        }

        for (int i = levelStart; i < levelEnd && i < n; i++) {
            printf("%d", a[i]);

            // Print spaces between nodes
            for (int j = 0; j < space; j++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    node* root = NULL;
    int count = 0;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete Max\n3. Print Max Heap (Array View)\n4. Print Max Heap (Tree View)\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value, &count);
                break;
            case 2:
                value = deleteMax(&root, &count);
                if (value != -1) {
                    printf("Deleted max value: %d\n", value);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("Heap is empty.\n");
                } else {
                    int arr[100];
                    int index = 0;
                    heapToArray(root, arr, &index);
                    printf("The max heap as an array is: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                if (count == 0) {
                    printf("Heap is empty.\n");
                } else {
                    int arr[100];
                    int index = 0;
                    heapToArray(root, arr, &index);
                    printHeapTreeView(arr, count);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
