class Solution {
   public:
    int solve(string s, string t, int ind1, int ind2) {
        if (ind2 == t.size()) return 1;
        if (ind1 == s.size()) return 0;

        int ways = 0;
        if (s[ind1] == t[ind2]) ways = solve(s, t, ind1 + 1, ind2 + 1);
        return ways + solve(s, t, ind1 + 1, ind2);
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][n] = 1;

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(t[j] == s[i]) dp[i][j] += dp[i+1][j+1];
                dp[i][j] += dp[i+1][j];
            }
        }

        return dp[0][0];
    }
};
