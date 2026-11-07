class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& curr) {
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, i+1, ans, curr);
        curr.pop_back();
        solve(nums, i+1, ans, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, ans, curr);

        return ans;
    }
};
