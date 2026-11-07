class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return 1;

        vector<int> dp(n, INT32_MAX);
        dp[n-1] = 0;
        dp[n-2] = (nums[n-2] == 0) ? INT32_MAX : 1;
        for(int i = n-3; i >= 0; i--) {
            for(int j = i; j <= i + nums[i] && j < n; j++) {
                if(dp[j] != INT32_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[0];
    }
};
