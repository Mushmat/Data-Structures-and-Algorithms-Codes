// Function to check if two binary trees are identical
bool isidentical(Node* r1, Node* r2) {
    // If both nodes are null, the trees are identical up to this point
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    // If one node is null and the other is not, the trees are not identical
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    // Recursively check if the left subtrees are identical
    bool left = isidentical(r1->left, r2->left);
    // Recursively check if the right subtrees are identical
    bool right = isidentical(r1->right, r2->right);

    // Check if the current node values are equal
    bool value = r1->data == r2->data;

    // If left subtrees, right subtrees, and current node values are all identical, return true
    if(left && right && value) {
        return true;
    } else {
        return false;
    }
}
