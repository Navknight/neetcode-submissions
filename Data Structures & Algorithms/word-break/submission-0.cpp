class Solution {
   public:
    unordered_map<int, bool> mp;
    bool solve(string& s, vector<string>& wordDict, int start) {
        if (start >= s.size()) return true;
        if(mp.find(start) != mp.end()) return mp[start];

        for (int i = start; i < s.size(); i++) {
            int len = i - start + 1;
            string str = s.substr(start, len);
            auto iter = find(wordDict.begin(), wordDict.end(), str);
            if (iter != wordDict.end()) {
                if (solve(s, wordDict, i + 1)) return mp[start] = true;
            }
        }

        return mp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) { return solve(s, wordDict, 0); }
};
