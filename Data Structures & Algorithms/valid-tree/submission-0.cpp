class Solution {
   public:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) return find(parent, parent[x]);
        return parent[x];
    }

    bool detectandunite(vector<int>& parent, vector<int>& rank, int a, int b) {
        int x = find(parent, a), y = find(parent, b);
        if (x == y) return true;

        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<int> parent, rank;
        parent = vector<int>(n);
        rank = vector<int> (n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (auto e : edges) {
            int a = e[0], b = e[1];
            if (detectandunite(parent, rank, a, b)) return false;
        }

        return true;
    }
};
