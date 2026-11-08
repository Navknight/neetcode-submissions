class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, end = 0, n = nums.size();
        for (int i = 0; i <= end && end < n; i++) {
            end = max(end, nums[i] + i);
        }
        return end >= n - 1;
    }
};
