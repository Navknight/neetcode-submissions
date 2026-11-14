class Solution {
public:
    int dfs(TreeNode* n, int mx) {
        if (!n) return 0;
        int good = n->val >= mx;
        mx = max(mx, n->val);
        return good + dfs(n->left, mx) + dfs(n->right, mx);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};