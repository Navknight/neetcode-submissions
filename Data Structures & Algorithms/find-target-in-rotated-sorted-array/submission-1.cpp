class Solution {
   public:
    int search(vector<int>& nums, int l, int r, int target) {
        int m = l + (r - l) / 2;
        while (l <= r) {
            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                return search(nums, l, m - 1, target);
            } else {
                return search(nums, m + 1, r, target);
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int def = 0;
        while (l < r) {
            int m = l + (r - l) / 2;
            if(nums[m] < nums[r]) r = m;
            else l = m+1;
        }
        
        def = l;

        return max(search(nums, 0, def, target), search(nums, def, n - 1, target));
    }
};
