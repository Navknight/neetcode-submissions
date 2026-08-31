class Solution {
   public:
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int ind, bool canBuy) {
        if (ind >= prices.size()) return 0;
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        int best = INT_MIN;

        if (canBuy)
            best = max(best, solve(prices, ind + 1, false) - prices[ind]);
        else
            best = max(best, solve(prices, ind + 2, true) + prices[ind]);

        best = max(best, solve(prices, ind + 1, canBuy));

        return dp[ind][canBuy] = best;
    }

    int maxProfit(vector<int>& prices) { 
        dp = vector<vector<int>> (prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, true);
         }
};
