class WordDictionary {
    struct Node {
        int child[26];
        bool done;
    };
    vector<Node*> nodes;
    Node* root;

   public:
    WordDictionary() {
        root = new Node();
        nodes.push_back(root);
    }

    void addWord(string word) {
        Node* ptr = root;
        for (auto& ch : word) {
            if (!ptr->child[ch - 'a']) {
                ptr->child[ch - 'a'] = nodes.size();
                nodes.push_back(new Node());
            }
            ptr = nodes[ptr->child[ch - 'a']];
        }

        ptr->done = true;
    }

    bool search(string word, Node* ptr) {
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (int l = 0; l < 26; l++) {
                    if (ptr->child[l] && search(word.substr(i + 1), nodes[ptr->child[l]]))
                        return true;
                }
                return false;
            } else {
                if (ptr->child[ch - 'a']) {
                    return search(word.substr(i + 1), nodes[ptr->child[ch - 'a']]);
                }
            }
            return false;
        }
        return ptr->done;
    }

    bool search(string word) {
        Node* ptr = root;
        return search(word, ptr);
    }
};
