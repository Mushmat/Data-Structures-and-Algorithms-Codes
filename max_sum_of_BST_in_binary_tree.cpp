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

// Class to store information about a subtree
class info {
public:
    int maxi; // Maximum value in the subtree
    int mini; // Minimum value in the subtree
    bool isBST; // Flag to check if the subtree is a BST
    int sum; // Sum of all nodes in the subtree
};

class Solution {
public:
    // Helper function to recursively solve the problem
    info solve(TreeNode* root, int &ans) {
        // Base case: if the root is null, return default values
        if (root == nullptr) {
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        // Recursively solve for the left and right subtrees
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        // Create an info object for the current node
        info currNode;
        currNode.sum = root->val + left.sum + right.sum; // Calculate the sum of the current subtree
        currNode.maxi = max(root->val, max(right.maxi, left.maxi)); // Find the maximum value in the current subtree
        currNode.mini = min(root->val, min(left.mini, right.mini)); // Find the minimum value in the current subtree
        
        // Check if the current subtree is a BST
        currNode.isBST = left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini);
        
        // If the current subtree is a BST, update the maximum sum
        if (currNode.isBST) {
            ans = max(ans, currNode.sum);
        }
        
        return currNode;
    }

    // Function to find the maximum sum of all BST subtrees in the binary tree
    int maxSumBST(TreeNode* root) {
        int maxsum = 0; // Initialize the maximum sum
        info temp = solve(root, maxsum); // Call the helper function to solve the problem
        return maxsum; // Return the maximum sum of BST subtrees
    }
};
