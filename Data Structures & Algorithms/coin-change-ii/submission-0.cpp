class Solution {
   public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int sum, int ind) {
        if (sum > amount || ind >= coins.size()) return 0;
        if (dp[ind][sum] != -1) return dp[ind][sum];
        if (sum == amount) return dp[ind][sum] = 1;

        return dp[ind][sum] = solve(coins, amount, sum, ind + 1) +
                                 solve(coins, amount, sum + coins[ind], ind);
    }

    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(coins, amount, 0, 0);
    }
};
