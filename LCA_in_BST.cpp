/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Function to find the lowest common ancestor of two nodes p and q in a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the root is nullptr, return nullptr
        if (root == nullptr) {
            return nullptr;
        }
        
        // If both p and q are greater than root, LCA must be in the right subtree
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If both p and q are less than root, LCA must be in the left subtree
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If one of p or q is on one side and the other is on the other side, or one is the root itself,
        // then the root is the lowest common ancestor
        return root;
    }
};
