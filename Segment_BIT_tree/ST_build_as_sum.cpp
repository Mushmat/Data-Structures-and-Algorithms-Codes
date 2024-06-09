#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

// Function to build the segment tree
void build(int node, int s, int e) {
    // Base case: if the segment has only one element
    if (s == e) {
        tree[node] = a[s]; // Assign the value of the single element to the node
        return;
    }
    
    // Recursive calls to build the left and right subtrees
    int mid = (s + e) / 2;
    build(2 * node, s, mid); // Build left subtree
    build(2 * node + 1, mid + 1, e); // Build right subtree
    
    // Combine the results from the left and right subtrees
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    int n;
    cin >> n;
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Build the segment tree
    build(1, 0, n - 1);

    // Output the segment tree nodes
    for (int i = 1; i < 2 * n; i++) {
        cout << tree[i] << endl;
    }

    return 0;
}
