class Solution {
   public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& reaches) {
        if (reaches[i][j]) return;
        reaches[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx >= 0 && ny >= 0 && nx < heights.size() && ny < heights[0].size() &&
                heights[i][j] <= heights[nx][ny]) {
                dfs(heights, nx, ny, reaches);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> rp(m, vector<bool>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dfs(heights, i, j, rp);
                }
            }
        }

        vector<vector<bool>> ra(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == m - 1 || j == n - 1) {
                    dfs(heights, i, j, ra);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rp[i][j] && ra[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
