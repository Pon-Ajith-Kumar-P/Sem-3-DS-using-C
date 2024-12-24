#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* createNode(int data) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to insert a node into the tree
node* insertNode(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for in-order traversal
void inOrderTraversal(node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function for pre-order traversal
void preOrderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function for post-order traversal
void postOrderTraversal(node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the smallest element
node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to find the largest element
node* findMax(node* root) {
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to delete a node
node* deleteNode(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to count the total number of nodes
int countNodes(node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the total number of external nodes (leaf nodes)
int countExternalNodes(node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

// Function to count the total number of internal nodes
int countInternalNodes(node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Function to determine the height of the tree
int treeHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to find the mirror image of the tree
node* mirrorTree(node* root) {
    if (root == NULL) {
        return NULL;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
}

// Function to delete the tree
void deleteTree(node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Function to print the tree vertically
void printTree(node* root, int level) 
{
    if (root == NULL) 
    {
        return;
    }

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++) 
    {
        printf("    ");
    }
    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

int main() {
    node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n ******MAIN MENU******* \n");
        printf("\n 1. Insert Element");
        printf("\n 2. Display Tree Horizontally");
        printf("\n 3. Preorder Traversal");
        printf("\n 4. Inorder Traversal");
        printf("\n 5. Postorder Traversal");
        printf("\n 6. Find the smallest element");
        printf("\n 7. Find the largest element");
        printf("\n 8. Delete an element");
        printf("\n 9. Count the total number of nodes");
        printf("\n 10. Count the total number of external nodes");
        printf("\n 11. Count the total number of internal nodes");
        printf("\n 12. Determine the height of the tree");
        printf("\n 13. Find the mirror image of the tree");
        printf("\n 14. Delete the tree");
        printf("\n 15. Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Horizontal display of the tree:\n");
                printTree(root, 0);
                break;
            case 2:
                printf("Horizontal display of the tree:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Preorder traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                if (root != NULL) {
                    node* minNode = findMin(root);
                    printf("The smallest element is: %d\n", minNode->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            case 7:
                if (root != NULL) {
                    node* maxNode = findMax(root);
                    printf("The largest element is: %d\n", maxNode->data);
                } else {
                    printf("The tree is empty.\n");
                }
                break;
            case 8:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Horizontal display of the tree:\n");
                printTree(root, 0);
                break;
            case 9:
                printf("The total number of nodes is: %d\n", countNodes(root));
                break;
            case 10:
                printf("The total number of external nodes is: %d\n", countExternalNodes(root));
                break;
            case 11:
                printf("The total number of internal nodes is: %d\n", countInternalNodes(root));
                break;
            case 12:
                printf("The height of the tree is: %d\n", treeHeight(root));
                break;
            case 13:
                root = mirrorTree(root);
                printf("The tree has been mirrored.\n");
                printf("Horizontal display of the tree:\n");
                printTree(root, 0);
                break;
            case 14:
                deleteTree(root);
                root = NULL;
                printf("The tree has been deleted.\n");
                break;
            case 15:
                deleteTree(root);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}