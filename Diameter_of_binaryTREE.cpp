// Function to calculate the diameter of the binary tree and the height of the tree
pair<int, int> diameterfast(Node* root) {
    // Base case: if the node is null, return a pair of 0,0 for diameter and height
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // Recursively get the diameter and height of the left subtree
    pair<int, int> left = diameterfast(root->left);
    // Recursively get the diameter and height of the right subtree
    pair<int, int> right = diameterfast(root->right);

    // Diameter options:
    // 1. Diameter of the left subtree
    int op1 = left.first;
    // 2. Diameter of the right subtree
    int op2 = right.first;
    // 3. Diameter passing through the current root (left height + right height + 1)
    int op3 = left.second + right.second + 1;

    // Create a pair to store the result
    pair<int, int> ans;
    // First element of the pair is the maximum diameter of the three options
    ans.first = max(op1, max(op2, op3));
    // Second element of the pair is the height of the current subtree (max of left height and right height + 1)
    ans.second = max(left.second, right.second) + 1;

    // Return the result pair
    return ans;
}

// Diameter of the tree is the first part of the ans pair returned by the diameterfast function.
