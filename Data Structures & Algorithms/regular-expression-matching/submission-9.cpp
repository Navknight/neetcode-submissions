class Solution {
   public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));

        dp[m][n] = true;
        for (int j = n - 1; j >= 0; j--) {
            if (j + 1 < n && p[j + 1] == '*') dp[m][j] = dp[m][j + 2];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j < n - 1 && p[j + 1] == '*') {
                    if (s[i] == p[j] || p[j] == '.') dp[i][j] = dp[i + 1][j] || dp[i][j + 2];
                    dp[i][j] = dp[i][j] || dp[i][j + 2];
                }

                else if (s[i] == p[j] || p[j] == '.') {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
