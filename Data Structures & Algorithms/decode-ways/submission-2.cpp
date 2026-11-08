class Solution {
   public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if (s[s.size() - 1] != '0') dp[s.size() - 1] = 1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] != '0') {
                if (10 * (s[i] - '0') + s[i + 1] - '0' <= 26) {
                    dp[i] += ((i + 2 < s.size()) ? dp[i + 2] : 1);
                }
                dp[i] += dp[i + 1];

            } else {
                dp[i] = 0;
            }
        }

        return dp[0];
    }
};
