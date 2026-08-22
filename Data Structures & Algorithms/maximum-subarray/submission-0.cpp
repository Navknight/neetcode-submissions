class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev1 = 0;
        prev1 = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int curr = max(nums[i], nums[i] + prev1);
            ans = max(ans, curr);
            prev1 = curr;
        }

        return ans;
    }
};
