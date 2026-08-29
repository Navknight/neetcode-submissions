class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (auto w : wordList) st.insert(w);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            string s = curr.first;
            int lvl = curr.second;

            if (s == endWord) return lvl;

            for (int i = 0; i < s.size(); i++) {
                string s1 = s;
                for (int ch = 0; ch < 26; ch++) {
                    s1[i] = (ch + 'a');
                    if (st.find(s1) != st.end()) {
                        q.push({s1, lvl + 1});
                        st.erase(s1);
                    }
                }
            }
        }

        return 0;
    }
};
