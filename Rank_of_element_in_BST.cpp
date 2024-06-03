#include <bits/stdc++.h>
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
        this->count = 0; // Initialize count as 0
    }
};

// Function to insert a node into the BST
Node* insertintoBST(Node* root, int d) {
    // Base case: if the tree is empty, create a new node
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    // Insert the node in the right subtree if the data is greater than the root's data
    if (d > root->data) {
        root->right = insertintoBST(root->right, d);
    }
    // Insert the node in the left subtree if the data is less than or equal to the root's data
    else {
        root->left = insertintoBST(root->left, d);
    }
    return root;
}

// Function to count the total number of nodes in the subtree rooted at 'root'
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // Initialize the count of the current node
    root->count = 1;
    // Recursively count nodes in the left and right subtrees
    int l1 = countNodes(root->left);
    int l2 = countNodes(root->right);
    // Update the count of the current node
    root->count += l1 + l2;
    return root->count;
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

// Function to find the rank of a node with the given value 'x'
int rankofx(Node* root, int x) {
    int r = 1;
    while (root) {
        if (root->data == x) {
            // If the node's data matches 'x', add the count of nodes in the right subtree
            r += countNodes(root->right);
            return r;
        }
        // If the node's data is greater than 'x', move to the left subtree
        else if (root->data > x) {
            r += 1 + countNodes(root->right);
            root = root->left;
        }
        // If the node's data is less than 'x', move to the right subtree
        else {
            root = root->right;
        }
    }
    return r;
}

int main() {
    Node* root = NULL;

    // Prompt the user to enter data to create the BST
    cout << "Enter data to create a Binary Search tree" << endl;
    takeInput(root);
    // Count the nodes in the BST to update the count values
    countNodes(root);

    // Prompt the user to enter the value to find its rank
    cout << "Rank of x" << endl;
    int x;
    cin >> x;

    // Find and print the rank of the given value
    cout << "RANK:" << endl;
    int rank = rankofx(root, x);
    cout << rank << endl;

    return 0;
}
