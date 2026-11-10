class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;

        vector<int> p(n, 0);
        iota(p.begin(), p.end(), 0);

        function<int(int)> find = [&](int u) { return p[u] == u ? u : p[u] = find(p[u]); };

        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return false;

            p[a] = b;
        }

        return true;
    }
};
