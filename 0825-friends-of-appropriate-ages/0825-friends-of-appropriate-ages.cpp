class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size(), ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (ages[i] < 15) break;
            int lo = upper_bound(ages.begin(), ages.end(), ages[i] * 0.5 + 7) - ages.begin();
            int hi = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            if (hi > lo) ans += hi - lo - 1;
        }

        return ans;
    }
};