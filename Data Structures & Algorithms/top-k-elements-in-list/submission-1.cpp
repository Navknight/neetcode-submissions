class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(),
                    [](auto& a, auto& b) { return a.second > b.second; });

        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(v[i].first);
        return ans;
    }
};
