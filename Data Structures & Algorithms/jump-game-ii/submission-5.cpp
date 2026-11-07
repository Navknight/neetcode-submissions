class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return 1;

        int farthest = nums[0], end = nums[0], ans = 0;
        for(int i = 1; i < n; i++) {
            if(i + nums[i] > farthest) {
                farthest = i + nums[i];
            }
            if(i == end || i == n-1) {
                ans++;
                end = farthest;
            }
        }

        return ans;
    }
};
