class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (words.find(endWord) == words.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();
            for (int i = 0; i < curr.size(); i++) {
                char original = curr[i];
                for (int j = 0; j < 26; j++) {
                    if ('a' + j == original) continue;
                    curr[i] = 'a' + j;
                    if (curr == endWord){
                        return level + 1;
                    }
                    if (words.find(curr) != words.end()) {
                        q.push({curr, level+1});
                        words.erase(curr);
                    }
                }
                curr[i] = original;
            }
        }

        return 0;
    }
};
