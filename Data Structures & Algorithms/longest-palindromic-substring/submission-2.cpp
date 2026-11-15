class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] || (j - i <= 2);
                }
            }
        }

        int maxl = 1, maxi = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (dp[i][j]) {
                    if (j - i + 1 > maxl) {
                        maxl = j - i + 1;
                        maxi = i;
                    }
                }
            }
        }

        return s.substr(maxi - 1, maxl);
    }
};
