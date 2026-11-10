class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> len;
        int ans = 0;
        for (int x : nums) {
            if (len.count(x)) continue;
            int left = len.count(x - 1) ? len[x - 1] : 0;
            int right = len.count(x + 1) ? len[x + 1] : 0;
            int total = left + right + 1;
            len[x] = len[x - left] = len[x + right] = total;
            ans = max(ans, total);
        }
        return ans;
    }
};