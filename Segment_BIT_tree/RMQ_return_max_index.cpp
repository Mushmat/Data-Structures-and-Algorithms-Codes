#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N];

// Function to build the segment tree for index of maximum element
void buildindexmax(int node, int s, int e) {
    if (s == e) {
        tree[node] = s; // Assign the index to the leaf node
        return;
    }
    int mid = (s + e) / 2;
    buildindexmax(2 * node, s, mid); // Build left subtree
    buildindexmax(2 * node + 1, mid + 1, e); // Build right subtree
    
    // Choose the index of the maximum element between the children
    tree[node] = (a[tree[2 * node]] >= a[tree[2 * node + 1]]) ? tree[2 * node] : tree[2 * node + 1];
}

// Function to find the index of maximum element in a range [l, r]
int indexmaxfromitoj(int node, int s, int e, int l, int r) {
    if (s > r || e < l) {
        return INT_MIN; // Return INT_MIN if the range is completely outside
    }
    if (l <= s && e <= r) {
        return tree[node]; // Return the index stored in the current node if the range is completely inside
    }
    int mid = (s + e) / 2;
    // Recursively find the index of maximum element in the left and right subtrees
    int q1 = indexmaxfromitoj(2 * node, s, mid, l, r);
    int q2 = indexmaxfromitoj(2 * node + 1, mid + 1, e, l, r);
    // Choose the index of maximum element between the results from left and right subtrees
    return (a[q1] >= a[q2]) ? q1 : q2;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    buildindexmax(1, 0, n - 1); // Build the segment tree for index of maximum element
    int y = indexmaxfromitoj(1, 0, n - 1, 0, n - 1); // Query for the index of maximum element in the entire array
    cout << "The max index is: " << y << endl;
    return 0;
}
