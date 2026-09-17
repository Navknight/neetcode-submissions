class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int maxJ = min(nums[i], n - 1 - i);
            for (int j = 1; j <= maxJ; j++) {
                int s = min(dp[i], dp[i + j]);
                dp[i] = s == INT_MAX ? dp[i] : min(dp[i], s + 1);
            }
        }

        return dp[0];
    }
};
