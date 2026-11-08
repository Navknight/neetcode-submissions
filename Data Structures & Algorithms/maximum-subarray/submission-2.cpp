class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0];
        int ans = dp;
        for (int i = 1; i < n; i++) {
            int x = max(dp + nums[i], nums[i]);
            dp = x;
            ans = max(ans, dp);
        }
        return ans;
    }
};
