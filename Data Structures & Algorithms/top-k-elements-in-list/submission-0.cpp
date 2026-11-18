class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto& i : nums) mp[i]++;
        for (auto& i : mp) {
            bucket[i.second].push_back(i.first);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            for (auto& j : bucket[i]) {
                if (ans.size() < k) {
                    ans.push_back(j);
                } else {
                    return ans;
                }
            }
        }

        return ans;
    }
};
