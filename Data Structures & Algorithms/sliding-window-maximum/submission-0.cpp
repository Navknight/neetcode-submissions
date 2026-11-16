class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        vector<int> ans;
        for (int r = 0; r < nums.size(); r++) {
            st.insert(nums[r]);
            if (r >= k) st.erase(st.find(nums[r - k]));
            if (r >= k - 1) ans.push_back(*st.rbegin());
        }
        return ans;
    }
};
