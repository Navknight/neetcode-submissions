class Solution {
   public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        dp[0] = 1;

        int last = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
