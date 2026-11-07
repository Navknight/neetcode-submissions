class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& t: tokens) {
            if(t == "+" || t == "-" || t == "/" || t == "*") {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();

                if(t == "+") {
                    st.push(x + y);
                }
                if(t == "-") {
                    st.push(y - x);
                }
                if(t == "/") {
                    st.push(y / x);
                }
                if(t == "*") {
                    st.push(x * y);
                }
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
