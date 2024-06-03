#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node with given data
    Node(int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

// Function to insert a node into the Binary Search Tree (BST)
Node* insertintoBST(Node* root, int d) {
    // Base case: if the tree is empty, create a new node
    if (root == NULL) {
        root = new Node(d);
        return root;
    }

    // If the data to insert is greater than the root's data, insert in the right subtree
    if (d > root->data) {
        root->right = insertintoBST(root->right, d);
    }
    // If the data to insert is less than or equal to the root's data, insert in the left subtree
    else {
        root->left = insertintoBST(root->left, d);
    }

    return root;
}

// Function to take input from the user and create a BST
void takeInput(Node* &root) {
    int data;
    cin >> data;

    // Continue taking input until the user enters -1
    while (data != -1) {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

// Function to perform level order traversal of the BST
void LevelOrderTraversal(Node* root) {
    // Create a queue to hold nodes for level order traversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // If temp is NULL, we have reached the end of a level
        if (temp == NULL) {
            cout << endl;

            // If queue is not empty, push NULL as marker for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        // If temp is not NULL, process the current node
        else {
            cout << temp->data << " ";

            // Push left child to queue if it exists
            if (temp->left) {
                q.push(temp->left);
            }
            // Push right child to queue if it exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create a Binary Search Tree (BST)" << endl;
    takeInput(root); // Create BST from user input
    cout << "Printing the BST in Level Order Traversal:" << endl;
    LevelOrderTraversal(root); // Print BST using level order traversal
}
