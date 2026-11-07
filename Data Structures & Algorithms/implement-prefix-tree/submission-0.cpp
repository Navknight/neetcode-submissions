class PrefixTree {
    struct PtNode {
        bool done;
        PtNode* next[26] = {};
    };

    PtNode* root;

   public:
    PrefixTree() { root = new PtNode(); }

    void insert(string word) {
        PtNode* ptr = root;
        for (auto& ch : word) {
            if (!ptr->next[ch - 'a']) {
                ptr->next[ch - 'a'] = new PtNode();
            }
            ptr = ptr->next[ch - 'a'];
        }

        ptr->done = true;
    }

    bool search(string word) {
        PtNode* ptr = root;
        for (auto& ch : word) {
            if (!ptr->next[ch - 'a']) {
                return false;
            }
            ptr = ptr->next[ch - 'a'];
        }
        return ptr->done;
    }

    bool startsWith(string prefix) {
        PtNode* ptr = root;
        for (auto& ch : prefix) {
            if (!ptr->next[ch - 'a']) {
                return false;
            }
            ptr = ptr->next[ch - 'a'];
        }
        return true;
    }
};
