// Function to search for a value in a binary search tree (BST)
bool SearchInBST(Node<int> *root, int x){
    Node<int> *temp = root; // Start from the root node
    // Traverse the tree until the current node is not NULL
    while(temp != NULL){
        // If the current node's data is equal to the target value x, return true
        if(temp->data == x){
            return true;
        }
        // If the target value x is less than the current node's data, move to the left subtree
        if(temp->data > x){
            temp = temp->left; // Move to the left child
        }
        // If the target value x is greater than the current node's data, move to the right subtree
        else{
            temp = temp->right; // Move to the right child
        }
    }
    // If the target value x is not found after traversing the entire tree, return false
    return false;
}
