class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;

        while (n) {
            int sum = 0;
            while (n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if (sum % 10 == sum) {
                if (sum == 1) return true;
                mp[sum]++;
                if (mp[sum] > 1) return false;
            }
            n = sum;
        }
        return false;
    }
};
