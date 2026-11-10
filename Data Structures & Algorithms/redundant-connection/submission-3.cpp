class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n + 1, 0);
        iota(p.begin(), p.end(), 0);

        function<int(int)> find = [&](int x) { return x == p[x] ? x : p[x] = find(p[x]); };

        vector<int> edge;

        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) {
                edge = e;
            }
            p[a] = b;
        }

        return edge;
    }
};
