class Solution {
   public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        int maxHeight = grid[0][0];

        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto curr = pq.top();
            visited[curr.second.first][curr.second.second] = true;
            maxHeight = max(maxHeight, curr.first);
            if (curr.second.first == n - 1 && curr.second.second == n - 1) return maxHeight;
            pq.pop();

            for (int d = 0; d < 4; d++) {
                int nx = dx[d] + curr.second.first;
                int ny = dy[d] + curr.second.second;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }

        return -1;
    }
};
