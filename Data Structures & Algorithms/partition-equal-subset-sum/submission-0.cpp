class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (j - nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }

        return dp[target];
    }
};
