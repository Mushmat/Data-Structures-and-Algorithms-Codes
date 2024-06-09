// Function to detect a cycle in a directed graph using DFS
bool checkcycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited, vector<int> adj[]) {
    // Mark the current node as visited and part of the current DFS path
    visited[node] = true;
    dfsvisited[node] = true;

    // Iterate over all adjacent nodes
    for(auto neighbour : adj[node]) {
        // If the adjacent node is not visited, recursively call DFS on it
        if(!visited[neighbour]) {
            bool cycledetected = checkcycleDFS(neighbour, visited, dfsvisited, adj);
            if(cycledetected) return true;
        }
        // If the adjacent node is already in the current DFS path, a cycle is detected
        else if(dfsvisited[neighbour]) {
            return true;
        }
    }

    // Remove the current node from the DFS path
    dfsvisited[node] = false;
    return false;
}

// Function to detect a cycle in a directed graph
bool isCyclic(int V, vector<int> adj[]) {
    // Maps to keep track of visited nodes and nodes in the current DFS path
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    // Iterate over all nodes in the graph
    for(int i = 1; i <= V; i++) {
        // If the node is not visited, start a DFS from that node
        if(!visited[i]) {
            bool cycledetected = checkcycleDFS(i, visited, dfsvisited, adj);
            if(cycledetected) return true;
        }
    }

    // If no cycle is detected in any DFS path, return false
    return false;
}
