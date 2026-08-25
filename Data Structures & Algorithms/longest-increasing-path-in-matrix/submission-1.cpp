class Solution {
   public:
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    map<pair<int,int>,int> mp;

    int backtrack(vector<vector<int>>& matrix, int i, int j) {
        if(mp.find({i,j}) != mp.end()) return mp[{i,j}];
        int ans = 0;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d], nj = j + dj[d];
            if (ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size()) {
                if (matrix[ni][nj] > matrix[i][j]) {
                    int length = 1 + backtrack(matrix, ni, nj);
                    ans = max(ans, length);
                }
            }
        }
        return mp[{i,j}] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> vis;

        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, 1 + backtrack(matrix, i, j));
            }
        }

        return ans;
    }
};
