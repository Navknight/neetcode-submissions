class Solution {
   public:
    bool solve(string s1, string s2, string s3, int ind1, int ind2) {
        if (ind1 == s1.size() && ind2 == s2.size()) {
            if (ind1 + ind2 == s3.size()) return true;
        }

        if (ind1 < s1.size() && s1[ind1] == s3[ind1 + ind2] && solve(s1, s2, s3, ind1 + 1, ind2))
            return true;

        if (ind2 < s2.size() && s2[ind2] == s3[ind1 + ind2] && solve(s1, s2, s3, ind1, ind2 + 1))
            return true;

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[m][n] = 1;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i + 1 <= m && s1[i] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i + 1][j];
                if (j + 1 <= n && s2[j] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
