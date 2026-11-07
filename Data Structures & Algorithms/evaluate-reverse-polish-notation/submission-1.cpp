class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto& t: tokens) {
            if(t == "+" || t == "-" || t == "/" || t == "*") {
                int x = stoi(st.top()); st.pop();
                int y = stoi(st.top()); st.pop();

                if(t == "+") {
                    st.push(to_string(x + y));
                }
                if(t == "-") {
                    st.push(to_string(y - x));
                }
                if(t == "/") {
                    st.push(to_string(y / x));
                }
                if(t == "*") {
                    st.push(to_string(x * y));
                }
            } else {
                st.push(t);
            }
        }

        return stoi(st.top());
    }
};
