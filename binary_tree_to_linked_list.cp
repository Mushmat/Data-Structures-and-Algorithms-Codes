class Solution {
public:
    // Declare a global variable to keep track of the previous node
    TreeNode* prev = nullptr;

    // Function to flatten the binary tree to a linked list in place
    void flatten(TreeNode* root) {
        // Base case: if the root is nullptr, return
        if (root == nullptr) 
            return;

        // Store the right child before modifying it
        TreeNode* rightTemp = root->right;

        // If prev exists, make it the right child of the current node
        if (prev != nullptr) {
            prev->left = nullptr;
            prev->right = root;
        }

        // Update prev to the current node
        prev = root;

        // Recursively flatten the left subtree
        flatten(root->left);
        // Recursively flatten the stored right subtree
        flatten(rightTemp);

        // Set the left child to nullptr after flattening
        root->left = nullptr;
    }
};
