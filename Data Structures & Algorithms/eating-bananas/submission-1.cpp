class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = INT32_MIN;
        for (auto& p : piles) r = max(r, p);

        int l = 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int time = 0;
            for (auto& p : piles) {
                time += (p + m - 1) / m;
            }

            if (time > h) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return r;
    }
};
