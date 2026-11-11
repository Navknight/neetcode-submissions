class Solution {
   public:
    unordered_map<int, string> mp = {{2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
                                     {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

    void solve(string digits, int ind, string s, vector<string>& ans) {
        if (ind == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (auto& ch : mp[digits[ind] - '0']) {
            solve(digits, ind + 1, s + ch, ans);
        }
    };

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> ans;
        solve(digits, 0, "", ans);
        return ans;
    }
};
