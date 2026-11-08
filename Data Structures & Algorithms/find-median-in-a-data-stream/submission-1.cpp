class MedianFinder {
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<>> upper;

   public:
    MedianFinder() {}

    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();
        if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if (lower.size() == upper.size()) {
            return (lower.top() + upper.top()) / 2.0;
        }
        return lower.top();
    }
};
