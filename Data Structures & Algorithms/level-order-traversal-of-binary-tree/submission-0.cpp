/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            vector<int> l;
            queue<TreeNode*> next;
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                l.push_back(curr->val);
                if (curr->left) next.push(curr->left);
                if (curr->right) next.push(curr->right);
            }

            ans.push_back(l);
            swap(q, next);
        }

        return ans;
    }
};
