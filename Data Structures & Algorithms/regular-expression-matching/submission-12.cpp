class Solution {
   public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, 0);

        dp[n] = true;
        for (int j = n - 1; j >= 0; j--) {
            if (j < n - 1 && p[j + 1] == '*') {
                dp[j] = dp[j + 2];
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            vector<bool> next(n + 1, 0);
            for (int j = n - 1; j >= 0; j--) {
                if (j < n - 1 && p[j + 1] == '*') {
                    if (s[i] == p[j] || p[j] == '.') {
                        next[j] = dp[j];
                    }
                    next[j] = next[j] || next[j + 2];
                } else if (s[i] == p[j] || p[j] == '.') {
                    next[j] = dp[j + 1];
                }
            }

            dp = next;
        }

        return dp[0];
    }
};
