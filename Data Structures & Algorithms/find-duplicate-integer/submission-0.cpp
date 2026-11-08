class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(10001, 0);
        for(auto& n: nums) {
            freq[n]++;
            if(freq[n] > 1) {
                return n;
            }
        }

        return -1;
    }
};
