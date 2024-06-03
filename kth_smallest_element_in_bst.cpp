/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to perform an inorder traversal and find the kth smallest element
    int solve(TreeNode* root, int &i, int k) {
        if (root == nullptr)
            return -1; // Base case: if the root is nullptr, return -1

        // Recur on the left subtree
        int left = solve(root->left, i, k);
        if (left != -1) {
            return left; // If the left subtree returns a valid result, propagate it upwards
        }

        // Increment the counter when visiting the current node
        i++;
        // If the current node is the kth smallest, return its value
        if (i == k) {
            return root->val;
        }

        // Recur on the right subtree
        return solve(root->right, i, k);
    }

    // Function to find the kth smallest element in a BST
    int kthSmallest(TreeNode* root, int k) {
        int i = 0; // Initialize a counter
        int ans = solve(root, i, k); // Call the helper function to get the answer
        return ans; // Return the kth smallest element
    }
};
