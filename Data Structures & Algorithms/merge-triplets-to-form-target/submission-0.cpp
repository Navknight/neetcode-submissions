class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool ok[3] = {0, 0, 0};
        for (auto& triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
                continue;

            for (int i = 0; i < 3; i++) {
                ok[i] = (triplet[i] == target[i]) || ok[i];
            }
        }

        return ok[0] && ok[1] && ok[2];
    }
};
