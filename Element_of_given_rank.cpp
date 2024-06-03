#include <iostream>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int count; // Count of nodes in the subtree rooted at this node

    // Constructor to initialize a node with given data
    Node(int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
        this->count = 1; // Initialize count as 1 for the current node
    }
};

// Function to insert a node into the BST and update the node counts
Node* insertintoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d); // Create a new node if the tree is empty
    }

    // Insert the node in the right subtree if the data is greater than the root's data
    if (d > root->data) {
        root->right = insertintoBST(root->right, d);
    }
    // Insert the node in the left subtree if the data is less than or equal to the root's data
    else {
        root->left = insertintoBST(root->left, d);
    }

    // Increment the count of nodes in the subtree
    root->count++;
    return root;
}

// Function to count the total number of nodes in the subtree rooted at 'root'
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // Recursively count nodes in the left and right subtrees
    int l1 = countNodes(root->left);
    int l2 = countNodes(root->right);
    // Return the sum of counts in both subtrees plus one for the current node
    return 1 + l1 + l2;
}

// Function to find the node with the given rank 'x'
Node* elementofrankx(Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }

    while (root) {
        // If the right subtree is not NULL
        if (root->right != NULL) {
            // Check if the rank of the current node matches 'x'
            if (x == 1 + root->right->count) {
                return root;
            }
            // If 'x' is less than the rank of the current node, move to the right subtree
            if (x < 1 + root->right->count) {
                root = root->right;
            }
            // Otherwise, move to the left subtree and adjust 'x'
            else {
                x = x - 1 - root->right->count;
                root = root->left;
            }
        } 
        // If the right subtree is NULL
        else {
            // Check if 'x' is the rank of the current node
            if (x == 1) {
                return root;
            }
            // Decrement 'x' to move to the left subtree
            x--;
            root = root->left;
        }
    }
    return root;
}

// Function to take input from the user and create a BST
void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = NULL;

    // Prompt the user to enter data to create the BST
    cout << "Enter data to create a Binary Search Tree" << endl;
    takeInput(root);

    // Prompt the user to enter the rank
    cout << "Given Rank" << endl;
    int r;
    cin >> r;

    // Find and print the element with the given rank
    cout << "Element:" << endl;
    Node* result = elementofrankx(root, r);
    if (result)
        cout << result->data << endl;
    else
        cout << "Rank out of bounds" << endl;

    return 0;
}
