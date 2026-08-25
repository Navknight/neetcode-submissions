class Solution {
   public:
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    int backtrack(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if(dp[i][j] != 0) return dp[i][j];
        int ans = 0;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d], nj = j + dj[d];
            if (ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size()) {
                if (matrix[ni][nj] > matrix[i][j]) {
                    int length = 1 + backtrack(matrix, dp, ni, nj);
                    ans = max(ans, length);
                }
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, 1 + backtrack(matrix, dp, i, j));
            }
        }

        return ans;
    }
};
