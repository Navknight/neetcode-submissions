class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;

        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int left = -1;
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int t = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, heights[t] * (i - left - 1));
            }
            s.push(i);
        }

        return maxArea;
    }
};
