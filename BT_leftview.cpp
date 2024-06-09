#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to build a tree from a given string
Node* buildTree(string str) {
    // Corner case: if the input string is empty or starts with 'N', return NULL
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Vector to store split string values
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Queue to store nodes for level order insertion
    queue<Node*> queue;
    queue.push(root);

    // Iterate over the string values to build the tree
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        vector<int> vec = leftView(root);
        for(int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Function to return a list containing elements of the left view of the binary tree
void solve(Node* root, vector<int> &ans, int level) {
    // Base case: if the node is null, return
    if(root == NULL)
        return;

    // If we entered into a new level, add the node's data to the answer
    if(level == ans.size())
        ans.push_back(root->data);

    // Recursively call for the left and right subtrees
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
