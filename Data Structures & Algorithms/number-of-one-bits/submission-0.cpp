class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int t = 32;
        int count = 0;
        while (t--) {
            int c = n & 1;
            cout<<c<<" ";
            count += c;
            n = n >> 1;
        }
        return count;
    }
};
