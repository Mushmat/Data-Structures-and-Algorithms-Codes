#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int sum; // Variable to store the prefix sum

    Node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
        this->sum = 0; // Initialize sum to 0
    }
};

// Function to insert a node into the BST
Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

// Function to compute the prefix sum up to a given node with value x
int prefixSum(Node* root, int x){
    if(root == NULL){
        return 0;
    }
    if (root->data < x) {
        // If the node's value is less than x, include its data in the sum
        root->sum = root->data + prefixSum(root->left, x) + prefixSum(root->right, x);
    } else if (root->data > x) {
        // If the node's value is greater than x, exclude it and its right subtree
        root->sum = prefixSum(root->left, x);
    } else { 
        // If the node's value is equal to x, include only the left subtree in the sum
        root->sum = prefixSum(root->left, x);
    }
    return root->sum;
}

// Function to compute the range sum between x and y in the BST
int rangeSum(Node* root, int x, int y){
    return (prefixSum(root, y) - prefixSum(root, x));
}

// Function to take input for creating the BST
void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create a Binary Search tree" << endl;
    takeInput(root);

    // Prompt for a number for which the prefix sum needs to be displayed
    cout << "Number for which prefix sum needs to be displayed: " << endl;
    int x;
    cin >> x;
    int prefixSumValue = prefixSum(root, x);
    cout << "Prefix Sum: " << prefixSumValue << endl;

    // Prompt for two integers for the range sum as x and y
    cout << "Enter two integers for the range sum as x and y:" << endl;
    int m, n;
    cin >> m >> n;
    int rangeSumValue = rangeSum(root, m, n);
    cout << "The Range Sum is: " << rangeSumValue << endl;
}
