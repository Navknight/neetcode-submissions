class Solution {
   public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q1;
        int count = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q1.push({i, j});
                else if (grid[i][j] == 1)
                    count++;
            }
        }

        int mins = 0;
        queue<pair<int, int>> q2;

        while (!q1.empty() || !q2.empty()) {
            if (!q1.empty()) {
                auto curr = q1.front();
                q1.pop();

                for (int d = 0; d < 4; d++) {
                    int ni = curr.first + dx[d];
                    int nj = curr.second + dy[d];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        count--;
                        q2.push({ni, nj});
                    }
                }
            } else {
                q1 = q2;
                mins++;
                q2 = queue<pair<int, int>>();
            }
        }

        return count == 0 ? mins : -1;
    }
};
