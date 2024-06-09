#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int a[N], tree[4 * N], lazy[4 * N];

// Function to build the segment tree
void build(int node, int s, int e) {
    if (s == e) {
        tree[node] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    build(2 * node, s, mid);
    build(2 * node + 1, mid + 1, e);
    
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Function to propagate lazy updates
void propagate(int node, int s, int e) {
    if (s == e) {
        tree[node] += lazy[node];
        lazy[node] = 0;
    } else {
        tree[node] += (e - s + 1) * lazy[node];
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }
}

// Function to perform range updates
void update(int node, int s, int e, int l, int r, int val) {
    propagate(node, s, e);
    if (e < l || r < s) return;
    if (s == e) {
        tree[node] += val;
    } else if (l <= s && e <= r) {
        lazy[node] += val;
        propagate(node, s, e);
    } else {
        int mid = (s + e) / 2;
        update(2 * node, s, mid, l, r, val);
        update(2 * node + 1, mid + 1, e, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// Function to perform range sum queries
int query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    propagate(node, s, e);
    if (s == e) {
        return tree[node];
    } else if (l <= s && e <= r) {
        return tree[node];
    } else {
        int mid = (s + e) / 2;
        int left = query(2 * node, s, mid, l, r);
        int right = query(2 * node + 1, mid + 1, e, l, r);
        return left + right;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    
    // Query sum of index 0 to 7
    int x = query(1, 0, n - 1, 0, 7);
    cout << "The sum of index 0 to 7 is: " << x << endl;
    
    // Query sum of index 2 to 4
    int y = query(1, 0, n - 1, 2, 4);
    cout << "The sum of index 2 to 4 is: " << y << endl;
    
    // Update range 2 to 4 by adding 2
    update(1, 0, n - 1, 2, 4, 2);
    
    // Query sum of index 0 to 7 after update
    int z = query(1, 0, n - 1, 0, 7);
    cout << "The sum of index 0 to 7 after update is: " << z << endl;
    
    // Output the segment tree nodes
    for (int i = 1; i < 2 * n; i++) {
        cout << tree[i] << endl;
    }
    return 0;
}
