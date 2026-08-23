class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int t = 32;
        int ans = 0;
        while (t--) {
            int b = n & 1;
            if (b == 1) {
                int mask = 1 << t;
                ans = ans | mask;
            }
            n = n >> 1;
        }

        return ans;
    }
};
