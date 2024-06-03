class Solution {
public:
    // Helper function to check if the binary tree is a valid BST
    bool isBST(TreeNode* root, long long int min, long long int max) {
        // Base case: if the root is null, it's a valid BST
        if (root == NULL)
            return true;
        
        // Check if the current node's value violates the BST property
        if (root->val <= min || root->val >= max) {
            return false;
        }
        
        // Recursively check the left subtree with updated max value as the current node's value
        bool left = isBST(root->left, min, root->val);
        // Recursively check the right subtree with updated min value as the current node's value
        bool right = isBST(root->right, root->val, max);
        
        // Return true if both left and right subtrees are valid BSTs
        return left && right;
    }

    // Main function to check if the binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial min and max values
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};
