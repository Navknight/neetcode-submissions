class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        if(n == 0) return m;
        if(m == 0) return n;

        vector<int> prev(n+1);
        for(int i = 0; i < n+1; i++) prev[i] = n-i;

        vector<int> curr(n+1);

        for(int i = m-1; i >= 0; i--) {
            curr[n] = m-i;
            for(int j = n-1; j >= 0; j--) {
                if(word1[i] == word2[j]) curr[j] = prev[j+1];
                else {
                    curr[j] = 1 + min({curr[j+1], prev[j], prev[j+1]});
                }
            }
            prev = curr;
        }

        return curr[0];
    }
};
