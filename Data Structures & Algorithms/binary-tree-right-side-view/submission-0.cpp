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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* right = nullptr;
            int len = q.size();

            while (len--) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    right = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (right) {
                ans.push_back(right->val);
            }
        }

        return ans;
    }
};
