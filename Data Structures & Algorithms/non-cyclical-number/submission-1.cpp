class Solution {
   public:
    int next(int n) {
        int s = 0;
        while (n) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while (fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};
