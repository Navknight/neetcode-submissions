class Solution {
   public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;
        int freq[26] = {0};
        for (int i = 0; i < m; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (auto& i : freq) {
            if (i != 0) return false;
        }
        return true;
    }
};
