#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with given key
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key into BST
struct Node *insert(struct Node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // return the (unchanged) node pointer
    return node;
}

// Function to do inorder traversal of BST
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to do preorder traversal of BST
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to do postorder traversal of BST
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Function to find the node with minimum key value in a subtree rooted at currNode
struct Node *minValueNode(struct Node *currNode)
{
    struct Node *current = currNode;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete the node with given key and return the new root
struct Node *deleteNode(struct Node *root, int key)
{
    // Base case: If the tree is empty, return NULL
    if (root == NULL)
        return root;

    // Recur down the tree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // If the key to be deleted is the same as root's key, then this is the node to be deleted
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of the BST: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of the BST: ");
    postorder(root);
    printf("\n");

    printf("Deleting key 20 from BST...\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified BST: ");
    inorder(root);
    printf("\n");

    return 0;
}
