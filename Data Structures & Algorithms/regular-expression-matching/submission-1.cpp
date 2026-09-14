class Solution {
public:
    bool solve(string s, string p, int ind1, int ind2) {
        if (ind1 == s.size() && ind2 == p.size())
            return true;
        if (ind2 == p.size())
            return false;

        if (ind2 + 1 < p.size() && p[ind2 + 1] == '*') {
            if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
                return solve(s, p, ind1 + 1, ind2) ||
                       solve(s, p, ind1, ind2 + 2);
            else
                return solve(s, p, ind1, ind2 + 2);
        } else if (ind1 < s.size() && (s[ind1] == p[ind2] || p[ind2] == '.'))
            return solve(s, p, ind1 + 1, ind2 + 1);
        else
            return false;
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[m][n] = true;
        for (int j = n - 1; j >= 0; j--)
            dp[m][j] = (j + 1 < n && p[j + 1] == '*') ? dp[m][j + 2] : false;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j + 1 < n && p[j + 1] == '*') {
                    if (s[i] == p[j] || p[j] == '.')
                        dp[i][j] = dp[i + 1][j] || dp[i][j + 2];
                    else
                        dp[i][j] = dp[i][j + 2];
                } else if (s[i] == p[j] || p[j] == '.')
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }
};