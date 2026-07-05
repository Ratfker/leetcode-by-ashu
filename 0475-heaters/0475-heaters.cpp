class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;

        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist = INT_MAX;
            if (it != heaters.end())   dist = min(dist, *it - house);
            if (it != heaters.begin()) dist = min(dist, house - *prev(it));
            ans = max(ans, dist);
        }

        return ans;
    }
};