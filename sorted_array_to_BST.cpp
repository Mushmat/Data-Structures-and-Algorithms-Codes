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
    // Recursive function to convert a sorted array to a balanced BST
    TreeNode* inordertoBST(int s, int e, vector<int> &in){
        // Base case: when the start index exceeds the end index
        if(s > e)
            return NULL;
        
        // Calculate the middle index of the current range
        int mid = (s + e) / 2;
        
        // Create a new node with the value at the middle index
        TreeNode* root = new TreeNode(in[mid]);
        
        // Recursively construct the left subtree with elements from s to mid-1
        root->left = inordertoBST(s, mid - 1, in);
        
        // Recursively construct the right subtree with elements from mid+1 to e
        root->right = inordertoBST(mid + 1, e, in);
        
        // Return the root of the current subtree
        return root;
    }
    
    // Main function to convert a sorted array to a BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the recursive function to construct the BST from the entire array
        return inordertoBST(0, nums.size() - 1, nums);
    }
};
