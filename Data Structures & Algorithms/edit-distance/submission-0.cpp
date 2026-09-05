class Solution {
   public:
    vector<vector<int>> dp;
    int solve(string word1, string word2, int ind1, int ind2) {
        if (ind2 == word2.size()) return word1.size() - ind1;
        if (ind1 == word1.size()) return word2.size() - ind2;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int opps = INT_MAX;
        if (word1[ind1] == word2[ind2])
            opps = min(opps, solve(word1, word2, ind1 + 1, ind2 + 1));
        else {
            opps = min(opps, 1 + solve(word1, word2, ind1 + 1, ind2));
            opps = min(opps, 1 + solve(word1, word2, ind1, ind2 + 1));
            opps = min(opps, 1 + solve(word1, word2, ind1 + 1, ind2 + 1));
        }

        return dp[ind1][ind2] = opps;
    }

    int minDistance(string word1, string word2) { 
        dp = vector<vector<int>> (word1.size(), vector<int> (word2.size(), -1));
        return solve(word1, word2, 0, 0); 
    }
};
