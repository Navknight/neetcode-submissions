class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int next2 = 0, next = cost[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int curr = min(next, next2) + cost[i];
            next2 = next;
            next = curr;
        }

        return min(next, next2);
    }
};
