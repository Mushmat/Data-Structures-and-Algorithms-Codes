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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

// Function to query the sum of elements in a range [l, r]
int sumitoj(int node, int s, int e, int l, int r) {
    // Case 1: No overlap
    if (s > r || e < l) {
        return 0;
    }
    // Case 2: Complete overlap
    if (l <= s && e <= r) {
        return tree[node];
    }
    // Case 3: Partial overlap
    int mid = (s + e) / 2;
    int q1 = sumitoj(2 * node, s, mid, l, r); // Query left subtree
    int q2 = sumitoj(2 * node + 1, mid + 1, e, l, r); // Query right subtree
    return q1 + q2;
}

// Function to query the maximum element in a range [l, r]
int maxfromitoj(int node, int s, int e, int l, int r) {
    // Case 1: No overlap
    if (s > r || e < l) {
        return INT_MIN;
    }
    // Case 2: Complete overlap
    if (l <= s && e <= r) {
        return tree[node];
    }
    // Case 3: Partial overlap
    int mid = (s + e) / 2;
    int q1 = maxfromitoj(2 * node, s, mid, l, r); // Query left subtree
    int q2 = maxfromitoj(2 * node + 1, mid + 1, e, l, r); // Query right subtree
    return max(q1, q2);
}

// Function to update the value of an element at a given index
void update(int node, int s, int e, int idx, int val) {
    // Base case: leaf node representing the element to be updated
    if (s == e) {
        a[s] = val; // Update the element in the original array
        tree[node] = val; // Update the corresponding node in the segment tree
        return;
    }
    // Recursive case: internal node
    int mid = (s + e) / 2;
    if (idx <= mid) {
        update(2 * node, s, mid, idx, val); // Update left subtree
    } else {
        update(2 * node + 1, mid + 1, e, idx, val); // Update right subtree
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]); // Update current node
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Input array elements
    }
    build(1, 0, n - 1); // Build the segment tree
    // Query the maximum element from the 2nd index to the 5th index
    int y = maxfromitoj(1, 0, n - 1, 1, 4);
    cout << "The max element from the 2nd index to the 5th index is: " << y << endl;
    // Update the value at the 3rd index to 10
    update(1, 0, n - 1, 2, 10);
    // Query the maximum element from the 2nd index to the 5th index after the update
    int z = maxfromitoj(1, 0, n - 1, 1, 4);
    cout << "The max element from the 2nd index to the 5th index after update is: " << z << endl;
    return 0;
}
