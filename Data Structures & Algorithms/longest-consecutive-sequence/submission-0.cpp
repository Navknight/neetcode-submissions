class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> parent(n), size(n, 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> mp;  // value -> index

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto join = [&](int a, int b) {
            int x = find(a), y = find(b);
            if (x == y) return;
            parent[y] = x;
            size[x] += size[y];
        };

        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) continue;
            mp[nums[i]] = i;

            if (mp.count(nums[i] - 1)) join(mp[nums[i] - 1], i);
            if (mp.count(nums[i] + 1)) join(mp[nums[i] + 1], i);

            ans = max(ans, size[find(i)]);
        }

        return ans;
    }
};