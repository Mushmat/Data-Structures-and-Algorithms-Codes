class Solution {
public:
    // Function to construct a balanced BST from a sorted linked list
    TreeNode* sortedLLtoBST(ListNode* &head, int n) {
        // Base case: if the number of nodes is zero or the head is null, return null
        if (n <= 0 || head == nullptr) {
            return nullptr;
        }

        // Construct left subtree by recursively converting the first half of the list
        TreeNode* left = sortedLLtoBST(head, n / 2);

        // Create the root node using the current head value
        TreeNode* root = new TreeNode(head->val);
        root->left = left; // Set the left child of the root

        // Move the head pointer to the next node
        head = head->next;

        // Construct the right subtree by recursively converting the remaining list
        root->right = sortedLLtoBST(head, n - n / 2 - 1);

        return root; // Return the root of the constructed BST
    }

    // Function to count the number of nodes in the linked list
    int countNodes(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        // Traverse the list and count nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Main function to convert sorted linked list to BST
    TreeNode* sortedListToBST(ListNode* head) {
        // Count the number of nodes in the linked list
        int n = countNodes(head);
        // Call the helper function to construct the BST from the linked list
        return sortedLLtoBST(head, n);
    }
};
