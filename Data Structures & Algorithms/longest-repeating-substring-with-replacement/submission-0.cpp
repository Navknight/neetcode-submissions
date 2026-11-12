class Solution {
   public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int l = 0, r = 0;

        int n = s.size();
        int ans = 0;
        int maxf = 0;

        while (r < n) {
            int ch = s[r++] - 'A';
            freq[ch]++;
            maxf = max(maxf, freq[ch]);

            if ((r - l) - maxf > k) {
                freq[s[l++] - 'A']--;
            }

            ans = max(ans, r - l);
        }

        return ans;
    }
};
