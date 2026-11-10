class Solution {
   public:
    void search(int n, vector<int>& cols, vector<vector<string>>& ans) {
        int r = cols.size();
        if (r == n) {
            vector<string> sol;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (j == cols[i])
                        s += 'Q';
                    else
                        s += '.';
                }
                sol.push_back(s);
            }

            ans.push_back(sol);
        }

        for (int i = 0; i < n; i++) {
            bool skip = false;
            for (int j = 0; j < cols.size(); j++) {
                if (i == cols[j]) {
                    skip = true;
                    break;
                }
                if (i == cols[j] + r - j || i == cols[j] - (r - j)) {
                    skip = true;
                    break;
                }
            }

            if (skip) continue;

            cols.push_back(i);
            search(n, cols, ans);
            cols.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;

        vector<vector<string>> ans;

        search(n, cols, ans);

        return ans;
    }
};
