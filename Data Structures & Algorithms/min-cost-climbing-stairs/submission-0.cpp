class Solution {
public:
    unordered_map<int, int> mp;

    int solve(vector<int>& cost, int ind) {
        if(ind >= cost.size()) return 0;
        if(ind >= cost.size() - 2) return cost[ind];

        if(mp.find(ind) != mp.end()) return mp[ind];

        return mp[ind] = cost[ind] + min(solve(cost, ind + 1), solve(cost, ind + 2));
    } 

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost, 0), solve(cost, 1));
    }
};
