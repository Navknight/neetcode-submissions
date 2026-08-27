class Solution {
   public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int bt(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if (vis[i][j]) return 0;

        int ans = 1;

        vis[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int ni = i + dy[d], nj = j + dx[d];

            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && !vis[ni][nj] &&
                grid[ni][nj] == 1)
                ans += bt(grid, vis, ni, nj);
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    ans = max(ans, bt(grid, vis, i, j));
                }
            }
        }

        return ans;
    }
};
