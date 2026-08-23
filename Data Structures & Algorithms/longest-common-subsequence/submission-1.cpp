class Solution {
   public:
    map<pair<int, int>, int> mp;
    int solve(string& t1, string& t2, int start1, int start2) {
        if (start1 == t1.size() || start2 == t2.size()) return 0;
        if (mp.find({start1, start2}) != mp.end()) return mp[{start1, start2}];
        int take = 0, one = 0, second = 0;

        if (t1[start1] == t2[start2]) {
            take = 1 + solve(t1, t2, start1 + 1, start2 + 1);
        } else {
            one = solve(t1, t2, start1 + 1, start2);
            second = solve(t1, t2, start1, start2 + 1);
        }

        return mp[{start1, start2}] = max({one, second, take});
    }

    int longestCommonSubsequence(string text1, string text2) { return solve(text1, text2, 0, 0); }
};
