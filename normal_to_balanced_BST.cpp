/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr, right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to perform an inorder traversal and store the values in a vector
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == nullptr) {
            return; // Base case: if the root is nullptr, return
        }
        inorder(root->left, in); // Recur on the left subtree
        in.push_back(root->val); // Visit the current node and add its value to the vector
        inorder(root->right, in); // Recur on the right subtree
    }

    // Helper function to convert a sorted vector to a balanced BST
    TreeNode* inordertoBST(int s, int e, vector<int>& in) {
        if (s > e) {
            return nullptr; // Base case: if the start index is greater than the end index, return nullptr
        }
        int mid = (s + e) / 2; // Find the middle element to be the root of the subtree
        TreeNode* root = new TreeNode(in[mid]); // Create a new node with the middle element
        root->left = inordertoBST(s, mid - 1, in); // Recur to construct the left subtree
        root->right = inordertoBST(mid + 1, e, in); // Recur to construct the right subtree
        return root; // Return the constructed subtree
    }

    // Function to balance an unbalanced BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderval; // Vector to store the inorder traversal of the BST
        inorder(root, inorderval); // Perform inorder traversal and fill the vector
        // Convert the sorted inorder traversal vector to a balanced BST
        return inordertoBST(0, inorderval.size() - 1, inorderval);
    }
};
