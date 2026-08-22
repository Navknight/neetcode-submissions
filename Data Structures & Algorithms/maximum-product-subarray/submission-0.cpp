class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxp(n);
        vector<int> minp(n);
        int m = -1e9;

        maxp[0] = nums[0];
        minp[0] = nums[0];
        m = nums[0];
        for (int i = 1; i < n; i++) {
        maxp[i] = max({maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i]});
            minp[i] = min({maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i]});
            m = max(m, maxp[i]);
        }

        return m;
    }
};
