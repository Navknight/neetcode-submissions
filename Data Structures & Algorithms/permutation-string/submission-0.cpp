class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (n < m) return false;
        vector<int> freq(26), window(26);

        for (auto& ch : s1) freq[ch - 'a']++;

        for (int i = 0; i < m; i++) {
            window[s2[i] - 'a']++;
        }

        for (int i = m; i < n; i++) {
            if (freq == window) {
                return true;
            }

            window[s2[i] - 'a']++;
            window[s2[i - m] - 'a']--;
        }

        return freq == window;
    }
};
