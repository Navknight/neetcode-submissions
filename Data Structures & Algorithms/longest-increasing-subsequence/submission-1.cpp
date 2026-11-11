class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int ans = 1;
        for (int i = 1; i < n; i++) {
            int t = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t = max(t, dp[j]);
                }
            }
            dp[i] += t;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
