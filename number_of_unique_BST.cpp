class Solution {
public:
    // Helper function to solve the problem recursively with dynamic programming
    int solve(int n, vector<int>& dp) {
        // Base case: if n is 0 or 1, there is only one unique BST possible
        if (n <= 1) {
            return 1;
        }
        // If the value of dp at index n is not -1, it means the result is already calculated, so return it
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = 0;
        // Iterate through each possible root node value from 1 to n
        for (int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique left and right subtrees
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        // Store the calculated result in dp[n] to avoid recalculating it in future calls
        return dp[n] = ans;
    }
    
    // Function to find the number of unique BSTs that can be formed with n nodes
    int numTrees(int n) {
        // Initialize a vector dp of size n+1 with all elements set to -1
        vector<int> dp(n + 1, -1);
        // Call the solve function to compute the result and return it
        return solve(n, dp);
    }
};
