class MinStack {
    stack<pair<int, int>> st;

   public:
    MinStack() {}

    void push(int val) {
        if (!st.empty()) {
            auto [top, topmin] = st.top();
            int newmin = min(topmin, val);
            st.push({val, newmin});
        } else {
            st.push({val, val});
        }
    }

    void pop() { st.pop(); }

    int top() {
        auto [top, topmin] = st.top();
        return top;
    }

    int getMin() {
        auto [top, topmin] = st.top();
        return topmin;
    }
};
