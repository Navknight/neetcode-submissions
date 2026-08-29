class Solution {
   public:
    bool dfs(vector<int>& color, int ind, vector<vector<int>>& graph) {
        if (color[ind] == 1) return true;
        if (color[ind] == 2) return false;

        color[ind] = 1;
        for (auto i : graph[ind]) {
            if (dfs(color, i, graph)) return true;
            color[i] = 2;
        }

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> color(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());

        for (auto v : prerequisites) {
            graph[v[0]].push_back(v[1]);
        }

        for (auto v : prerequisites) {
            if (color[v[0]] == 0) {
                if (dfs(color, v[0], graph)) {
                    return false;
                }
                color[v[0]] = 2;
            }
        }

        return true;
    }
};
