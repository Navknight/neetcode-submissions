class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);  // fake 1 at index 0
        nums.push_back(1);             // fake 1 at index n+1
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // dp[l][r] = max coins from bursting every balloon in [l, r]

        for (int l = n; l >= 1; l--) {          // bigger l filled first
            for (int r = l; r <= n; r++) {      // smaller r filled first
                for (int i = l; i <= r; i++) {  // i = last balloon burst in [l, r]
                    int value = nums[l - 1] * nums[i] * nums[r + 1];
                    dp[l][r] = max(dp[l][r], value + dp[l][i - 1] + dp[i + 1][r]);
                }
            }
        }
        return dp[1][n];
    }
};