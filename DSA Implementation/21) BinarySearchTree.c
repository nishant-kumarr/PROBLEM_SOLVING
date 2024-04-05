/*

Hey Visitor ! This is the code of mine that facilitates the following seven operation of a Binary Search Tree.
Operations are : create, insert, traverse(preorder, inorder, postorder), search and element, find minm and 
maxm value, and find the height of the Binary search tree.
Feel free the explore the code below : 

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct Node *search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

struct Node *findSmallest(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node *findLargest(struct Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int findHeight(struct Node *root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    int choice, value;
    struct Node *temp;

    do {
        printf("----------------------------------------");
        printf("\n\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Search for an element\n");
        printf("6. Find the smallest element\n");
        printf("7. Find the largest element\n");
        printf("8. Find the height of the BST\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp != NULL) {
                    printf("Element %d found in the BST.\n", value);
                } else {
                    printf("Element %d not found in the BST.\n", value);
                }
                break;
            case 6:
                temp = findSmallest(root);
                printf("Smallest element: %d\n", temp->data);
                break;
            case 7:
                temp = findLargest(root);
                printf("Largest element: %d\n", temp->data);
                break;
            case 8:
                printf("Height of the BST: %d\n", findHeight(root));
                break;
            case 9:
                printf("Exiting the program\n\n.");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
