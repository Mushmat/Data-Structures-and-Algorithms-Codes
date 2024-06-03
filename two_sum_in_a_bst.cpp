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
    // Function to perform an inorder traversal of the BST and store values in a vector
    void inorder(TreeNode * root, vector<int> &in){
        if(root == NULL)
            return;
        inorder(root->left,in);
        in.push_back(root->val); // Store the value of the current node
        inorder(root->right,in);
    }
    
    // Function to find if there are two distinct nodes in the BST with values summing up to k
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderval; // Vector to store inorder traversal values
        inorder(root,inorderval); // Perform inorder traversal and store values
        
        // Initialize pointers for two-sum approach
        int i = 0, j = inorderval.size()-1;
        
        // Two-sum approach to find if there are two distinct nodes with sum k
        while(i < j){
            int sum = inorderval[i] + inorderval[j];
            if(sum == k){ // If sum equals k, return true
                return true;
            }
            else if(sum > k) // If sum is greater than k, decrement j
                j--;
            else // If sum is less than k, increment i
                i++;
        }
        // If no such pair found, return false
        return false;
    }
};
