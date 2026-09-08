class Solution {
   public:
    int minDistance(string word1, string word2) {
        //prefix based dp - Q that I ask is, what do I need to do to match the first i characters of word1 to the first j characters of word2.
        int m = word1.size(), n = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;

        vector<int> prev(n + 1);
        iota(prev.begin(), prev.end(), 0); // this is when word1 is empty, so I have no choice but to insert the number of characters required.
        vector<int> curr(n + 1);

        for (int i = 1; i < m + 1; i++) {
            curr[0] = i; // the first column is word2 empty, so I have no choice but to delete the number of characters in word1.
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1]; //if word1 == word2, no operations are reuired, we just carry the operations till now in memory forward.
                else curr[j] = 1 + min({prev[j-1], //replace a char
                curr[j-1], //insert a char
                prev[j] // delete a char
                });
            }
            prev = curr;
        }

        return curr[n];
    }
};
