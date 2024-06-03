/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Recursive helper function to construct BST from preorder traversal
    TreeNode * solve(vector<int> &preorder, int mini, int maxi, int &i){
        // Base case: if index exceeds the size of the preorder list, return NULL
        if(i >= preorder.size()){
            return NULL;
        }

        // If the current value does not lie within the valid range, return NULL
        if(preorder[i] < mini || preorder[i] > maxi){
            return NULL;
        }

        // Create a new TreeNode with the current value and move to the next index
        TreeNode *root = new TreeNode(preorder[i++]);

        // Recursively build the left subtree with updated constraints
        root->left = solve(preorder, mini, root->val, i);

        // Recursively build the right subtree with updated constraints
        root->right = solve(preorder, root->val, maxi, i);

        // Return the constructed subtree rooted at 'root'
        return root;
    }

    // Main function to build BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN; // Minimum possible value for a node
        int maxi = INT_MAX; // Maximum possible value for a node
        int i = 0; // Index to track the current element in preorder traversal

        // Call the recursive helper function to construct the BST
        return solve(preorder, mini, maxi, i);
    }
};
