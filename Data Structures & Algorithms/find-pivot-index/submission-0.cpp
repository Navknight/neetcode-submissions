class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());
        for(int i = 1; i < nums.size(); i++) {
            left[i]  = left[i-1] + nums[i -1];
        }
        for(int i = nums.size()-2; i >= 0; i--) {
            right[i] = right[i+1] + nums[i + 1];
        }

        int ans ;
        for(ans = 0; ans < nums.size(); ans++) {
            if(right[ans] == left[ans]) {
                break;
            }
        }

        return ans == nums.size() ? -1: ans;
    }
};