class Solution {
   public:
    unordered_map<int, bool> mp;
    bool solve(string& s, vector<string>& wordDict, int start) {
        if (start >= s.size()) return true;
        if (mp.find(start) != mp.end()) return mp[start];
        for (auto str : wordDict) {
            if (str.size() <= s.size() - start && str == s.substr(start, str.size()) &&
                solve(s, wordDict, start + str.size()))
                return mp[start] = true;
        }

        return mp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) { return solve(s, wordDict, 0); }
};
