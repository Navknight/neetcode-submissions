class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(heights[l], heights[r]) * (r - l));
            if (heights[r] > heights[l])
                l++;
            else
                r--;
        }

        return ans;
    }
};
