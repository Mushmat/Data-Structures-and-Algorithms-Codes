class Solution {
public:
    // Function to check if a given graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        // Initialize a color vector to store colors of nodes (-1 indicates uncolored)
        vector<int> color(graph.size(), -1);

        // Iterate through all nodes in the graph
        for (int i = 0; i < graph.size(); i++) {
            // If the node is not colored, start a BFS from that node
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0; // Color the starting node with color 0

                // Perform BFS
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    // Check all adjacent nodes
                    for (auto nei : graph[node]) {
                        // If the adjacent node is not colored, color it with the opposite color
                        if (color[nei] == -1) {
                            color[nei] = !color[node];
                            q.push(nei);
                        } 
                        // If the adjacent node has the same color, the graph is not bipartite
                        else if (color[nei] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        // If no conflicts in coloring, the graph is bipartite
        return true;
    }
};
