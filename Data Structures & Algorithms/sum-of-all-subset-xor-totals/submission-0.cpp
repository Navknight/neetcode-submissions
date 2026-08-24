class Solution {
public:
    int total = 0;
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return total;
    }

    void backtrack(vector<int>& nums, int idx, int sum) {
        total += sum;

        for(int i = idx; i < nums.size(); i++) 
            backtrack(nums, i+1, sum ^ nums[i]);
    }
};