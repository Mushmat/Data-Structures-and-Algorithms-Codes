vector<vector<int>> printGraph(int v, vector<pair<int,int>> &edges) {
        vector<vector<int>> ans(v);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i].first;
            int w = edges[i].second;
            ans[u].push_back(w);
            ans[w].push_back(u);
        }
        vector<vector<int> > adj(v);
        for(int i = 0; i < v; i++){
            for(int j = 0; j<ans[i].size(); j++){
                adj[i].push_back(ans[i][j]);
            }
        }
        return adj;
    }
