// Function to find the node with the minimum value in a BST
Node* minVal(Node* node) {
    Node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
Node* deletefromBST(Node* root, int val) {
    // Base case: if the tree is empty, return NULL
    if (root == NULL) {
        return root;
    }

    // If the value to be deleted is found
    if (root->data == val) {
        // Case 1: Node with no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2a: Node with only left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2b: Node with only right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        if (root->left != NULL && root->right != NULL) {
            // Find the inorder successor (smallest in the right subtree)
            int mini = minVal(root->right)->data;
            // Replace root's data with the inorder successor's data
            root->data = mini;
            // Delete the inorder successor
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }
    // If the value to be deleted is smaller than the root's data, go to the left subtree
    else if (root->data > val) {
        root->left = deletefromBST(root->left, val);
    }
    // If the value to be deleted is greater than the root's data, go to the right subtree
    else {
        root->right = deletefromBST(root->right, val);
    }

    return root;
}
