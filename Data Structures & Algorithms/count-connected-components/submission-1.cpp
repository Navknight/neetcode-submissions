class Solution {
   public:
    void dfs(vector<bool>& vis, vector<vector<int>>& graph, int node) {
        if (vis[node]) return;

        vis[node] = true;
        for (auto n : graph[node]) {
            dfs(vis, graph, n);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> vis(n, false);
        int count = 0;
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(vis, graph, i);
            }
        }

        return count;
    }
};
