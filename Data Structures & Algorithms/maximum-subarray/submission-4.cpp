class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0];
        int ans = dp;
        for (int i = 1; i < n; i++) {
            dp = max(dp + nums[i], nums[i]);
            ans = max(ans, dp);
        }
        return ans;
    }
};
