class Solution {
private:
    // Function to detect a cycle in an undirected graph using BFS
    bool isCycleBFS(int src, vector<int> adj[], unordered_map<int, bool>& visited) {
        unordered_map<int, int> parent; // Map to track the parent of each node
        parent[src] = -1; // The source node has no parent
        visited[src] = true; // Mark the source node as visited
        queue<int> q; // Queue for BFS
        q.push(src); // Push the source node into the queue
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            
            // Explore all adjacent nodes
            for (auto neighbour : adj[front]) {
                // If the adjacent node is visited and is not the parent of the current node, a cycle is detected
                if (visited[neighbour] && neighbour != parent[front]) {
                    return true;
                }
                // If the adjacent node is not visited, mark it as visited and set its parent
                else if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return false; // No cycle detected
    }

public:
    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool> visited; // Map to track visited nodes
        // Check for cycle in each component of the graph
        for (int i = 0; i < V; i++) {
            // If the node is not visited, start a BFS from that node
            if (!visited[i]) {
                bool ans = isCycleBFS(i, adj, visited);
                // If a cycle is detected, return true
                if (ans) return true;
            }
        }
        // No cycle detected in any component
        return false;
    }
};
