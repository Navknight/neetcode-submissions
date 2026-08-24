class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 2) return strs[0];
        string ans = "";
        int minind= 1e9;
        for(auto s : strs) {
            minind = s.size() > minind ? minind : s.size();
        }
        cout<<minind<<endl;
        int len = 0;
        while(minind--) {
            for(int i = 1; i < strs.size(); i++) {
                if(strs[i][len] == strs[i-1][len]) {
                    continue;
                } else {
                    return ans;
                }
            }

            ans += strs[0][len];
            len++;
        }

        return ans;
    }
};