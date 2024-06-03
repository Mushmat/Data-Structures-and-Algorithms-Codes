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
private:
    TreeNode *first;  // Pointer to the first node out of order
    TreeNode *prev;   // Pointer to the previously visited node
    TreeNode *middle; // Pointer to the middle node out of order (if exists)
    TreeNode *last;   // Pointer to the last node out of order
    
private:
    // Helper function to perform inorder traversal and find misplaced nodes
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        // Compare the current node with the previous one
        if(prev != NULL && (root->val < prev->val)){
            // If this is the first misplaced node encountered
            if(first == NULL){
                first = prev;   // Set the first misplaced node
                middle = root;  // Set it as the middle node
            }
            else{
                last = root;    // Set the last misplaced node
            }
        }
        prev = root; // Update prev for the next comparison
        inorder(root->right); // Traverse the right subtree
    }
    
public:
    // Main function to recover the BST
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; // Initialize pointers
        prev = new TreeNode(INT_MIN); // Initialize prev with a very small value
        inorder(root); // Perform inorder traversal to find misplaced nodes
        
        // If both first and last misplaced nodes are found, swap their values
        if(first && last) swap(first->val, last->val);
        // If only first and middle misplaced nodes are found, swap their values
        else if (first && middle) swap(first->val, middle->val);
    }
};
