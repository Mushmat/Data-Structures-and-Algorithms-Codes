#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;

// Function to get the range sum from 1 to id using a Binary Indexed Tree (BIT)
int query(int id) {
    int ans = 0;
    // Traverse the BIT from id to 0
    while (id > 0) {
        ans += bit[id]; // Add the current BIT value to the result
        id -= (id & -id); // Move to the parent node in BIT
    }
    return ans;
}

// Function to update the BIT with a value at a specific index
void update(int id, int val) {
    // Traverse the BIT from id to n
    while (id <= n) {
        bit[id] += val; // Update the current BIT value with the given value
        id += (id & -id); // Move to the next node in BIT
    }
}

int main() {
    cin >> n;
    bit = vector<int>(n + 1, 0); // Initialize BIT with size n+1 and all values as 0
    vector<int> a(n + 1); // Initialize the array to store the input values

    // Read the input values and update the BIT
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]); // Update the BIT with the input value at index i
    }

    // Process queries and updates
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Range sum query from l to r
            int l, r;
            cin >> l >> r;
            int ans = query(r) - query(l - 1); // Calculate the range sum
            cout << ans << endl;
        } else {
            // Point update at index id with value val
            int id, val;
            cin >> id >> val;
            update(id, -a[id]); // Remove the old value from BIT
            a[id] = val; // Update the array with the new value
            update(id, a[id]); // Add the new value to BIT
        }
    }
}
