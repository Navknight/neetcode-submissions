class Solution {
   public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        dp[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= n; j++) {
                if (s[i] == '(') {
                    dp[i][j] = (j + 1 <= n) && dp[i + 1][j + 1];
                } else if (s[i] == ')') {
                    dp[i][j] = (j >= 1) && dp[i + 1][j - 1];
                } else {
                    dp[i][j] = dp[i + 1][j] || (j >= 1) && dp[i + 1][j - 1] ||
                               (j + 1 <= n) && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
