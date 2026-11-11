class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][0] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        if (ans.size() && ans.back()[0] <= newInterval[0] && ans.back()[1] >= newInterval[0]) {
            auto t = ans.back();
            ans.pop_back();
            ans.push_back({min(newInterval[0], t[0]), max(newInterval[1], t[1])});
        } else {
            ans.push_back(newInterval);
        }

        for (; i < n; i++) {
            if (ans.back()[0] <= intervals[i][0] && ans.back()[1] >= intervals[i][0]) {
                auto t = ans.back();
                ans.pop_back();
                ans.push_back({min(t[0], intervals[i][0]), max(t[1], intervals[i][1])});
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
