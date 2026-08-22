class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26, vector<int>());
        vector<bool> present(26, false);

        for (auto w : words) {
            for (auto ch : w) {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int j;
            for (j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) break;
            }
            if (j < min(w1.size(), w2.size()))
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
            else if (w1.size() > w2.size())
                return "";
        }

        // topo sort
        vector<int> indegree(26, 0);
        for (auto v : adj) {
            for (auto i : v) indegree[i]++;
        }

        queue<int> q;
        int total = 0;
        for (int i = 0; i < 26; i++)
            if (present[i]) {
                total++;
                if (indegree[i] == 0) q.push(i);
            }

        string order = "";

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order += (curr + 'a');
            for (auto i : adj[curr]) {
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }

        return order.size() == total ? order : "";
    }
};
