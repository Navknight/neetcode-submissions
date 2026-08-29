class Solution {
   public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) : parent(n), rank(n) { iota(parent.begin(), parent.end(), 0); }

        int find(int x) {
            if (parent[x] != x) return parent[x] = find(parent[x]);
            return x;
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return false;
            }
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[y] == rank[x]) rank[x]++;
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n + 1);

        for (auto& edge : edges) {
            if (!dsu->unite(edge[0], edge[1])) return edge;
        }

        return vector<int>();
    }
};
