class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> nums2(n + 2, 1);
        for (int i = 0; i < n; i++) {
            nums2[i + 1] = nums[i];
        }

        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                int maxcoins = INT32_MIN;
                for (int i = l; i <= r; i++) {
                    maxcoins = max(maxcoins, nums2[l - 1] * nums2[i] * nums2[r + 1] + dp[l][i - 1] +
                                                 dp[i + 1][r]);
                }
                dp[l][r] = max(dp[l][r], maxcoins);
            }
        }

        return dp[1][n];
    }
};