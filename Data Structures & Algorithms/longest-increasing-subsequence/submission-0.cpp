class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(auto i: nums) {
            auto iter = lower_bound(tails.begin(), tails.end(), i);
            if(iter == tails.end()) {
                tails.push_back(i);
            } else {
                *iter = i;
            }
        }

        return tails.size();
    }
};
