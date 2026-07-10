class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long first = LLONG_MAX, second = LLONG_MAX;
        for (int n : nums) {
            if (n <= first) first = n;
            else if (n <= second) second = n;
            else return true;
        }
        return false;
    }
};