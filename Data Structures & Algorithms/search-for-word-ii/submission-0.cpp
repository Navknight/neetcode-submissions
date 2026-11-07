class Solution {
    struct TrieNode {
        bool done = false;
        vector<TrieNode*> next = vector<TrieNode*>(26, nullptr);
    };

    TrieNode* root = new TrieNode();

    void add(string word) {
        TrieNode* ptr = root;
        for (auto& ch : word) {
            if (!ptr->next[ch - 'a']) ptr->next[ch - 'a'] = new TrieNode();
            ptr = ptr->next[ch - 'a'];
        }
        ptr->done = true;
    }

   public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void search(vector<vector<char>>& board, TrieNode* node, vector<vector<bool>>& visited,
                unordered_set<string>& ans, int i, int j, string word) {
        if (!node->next[board[i][j] - 'a']) return;

        visited[i][j] = true;
        word = word + board[i][j];
        node = node->next[board[i][j] - 'a'];
        if (node->done) {
            ans.insert(word);
        }

        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < board.size() && nx >= 0 && ny >= 0 && ny < board[0].size() &&
                !visited[nx][ny]) {
                search(board, node, visited, ans, nx, ny, word);
            }
        }
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& word : words) {
            add(word);
        }
        unordered_set<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                TrieNode* ptr = root;
                search(board, ptr, visited, ans, i, j, "");
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
