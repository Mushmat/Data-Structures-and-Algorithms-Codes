class Solution {
public:
    vector<vector<long long>> table; // 2D vector to store precomputed combinations
    int mod = 1e9 + 7; // Modulo value for avoiding integer overflow
    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 1; // Base case: if the size of the array is 2 or less, there's only one way to reorder
        }
        vector<int> left, right; // Arrays to store elements smaller and larger than the first element
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]); // Elements smaller than the first element go to the left array
            else
                right.push_back(nums[i]); // Elements larger than the first element go to the right array
        }
        // Recursively compute the number of ways to reorder left and right arrays
        long long lans = dfs(left) % mod;
        long long rans = dfs(right) % mod;
        int llen = left.size();
        // Calculate the total number of ways by combining left and right arrays with the first element
        return (((table[n - 1][llen] * lans) % mod) * rans) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1); // Resize the table to accommodate n+1 rows
        // Populate the table with combinations using Pascal's Triangle
        for (int i = 0; i < n + 1; i++) {
            table[i] = vector<long long>(i + 1, 1); // Initialize each row with 1
            for (int j = 1; j < i; j++) {
                // Calculate combination values using the formula C(n, k) = C(n-1, k-1) + C(n-1, k)
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        // Calculate the total number of ways to reorder the array and subtract 1 (for the original order)
        long long ans = dfs(nums);
        return (ans % mod) - 1;
    }
};
