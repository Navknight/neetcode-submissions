class DSU {
    vector<int> parent;

   public:
    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void join(int x, int y) { parent[find(x)] = find(y); }

    DSU(int x) {
        parent = vector<int>(x);
        for (int i = 0; i < x; i++) parent[i] = i;
    }
};

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU* dsu = new DSU(n * n);

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        vector<int> pos(n * n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = i * n + j;
            }
        }

        vector<bool> active(n * n, 0);

        for (int t = 0; t < n * n; t++) {
            int cell = pos[t];
            active[cell] = true;

            int x = cell / n;
            int y = cell % n;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && active[nx * n + ny]) {
                    dsu->join(cell, nx * n + ny);
                }
            }

            if (dsu->find(0) == dsu->find((n - 1) * n + n - 1)) return t;
        }

        return -1;
    }
};
