// Function to create a mapping from node value to its index in the inorder array
void createmapping(int in[], map<int,int> &nodeToIndex, int n) {
    // Loop through each element in the inorder array
    for(int i = 0; i < n; i++) {
        // Store the index of each element in the map
        nodeToIndex[in[i]] = i;
    }
}

// Function to build the binary tree from inorder and postorder traversal arrays
Node *solve(int in[], int post[], int &index, int inorderstart, int inorderend, int n, map<int,int> &nodeToIndex) {
    // Base case: if index is out of bounds or start index is greater than end index
    if(index < 0 || inorderstart > inorderend) {
        return NULL;
    }
    
    // Get the current element from postorder array and decrement the index
    int element = post[index--];
    // Create a new node with the current element
    Node* root = new Node(element);
    
    // Get the position of the current element in the inorder array
    int position = nodeToIndex[element];
    
    // Recursively build the right subtree
    root->right = solve(in, post, index, position + 1, inorderend, n, nodeToIndex);
    // Recursively build the left subtree
    root->left = solve(in, post, index, inorderstart, position - 1, n, nodeToIndex);
    
    // Return the root of the subtree
    return root;
}

// Function to initialize the process of building the tree
Node* buildtree(int in[], int post[], int n) {
    // Initialize the postorder index to the last element
    int postorderindex = n - 1;
    // Map to store the node value to its index in the inorder array
    map<int,int> nodetoindex;
    // Create the mapping from node value to index
    createmapping(in, nodetoindex, n);
    // Build the tree using the solve function and return the root
    Node* ans = solve(in, post, postorderindex, 0, n - 1, n, nodetoindex);
    return ans;
}
