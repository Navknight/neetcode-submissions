class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, end = 0, n = nums.size();
        for(int i = 0; i <= end && end < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if(farthest > end) {
                end = farthest;
            }
        }
        return end >= n-1;
    }
};
