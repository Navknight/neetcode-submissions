class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& str: strs) {
            int l = str.size();
            ans += to_string(l);
            ans += "_";
            ans += str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size();) {
            int j = i;
            for(; j < s.size(); j++) {
                if(s[j] == '_') break;
            }
            int l = stoi(s.substr(i, j-i));
            ans.push_back(s.substr(j+1, l));
            i = j +l + 1;
        }
        return ans;
    }
};
