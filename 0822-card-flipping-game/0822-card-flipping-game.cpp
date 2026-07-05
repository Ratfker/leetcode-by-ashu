class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        int n = fronts.size();
        for (int i = 0; i < n; i++)
            if (fronts[i] == backs[i])
                same.insert(fronts[i]);

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!same.count(fronts[i])) ans = min(ans, fronts[i]);
            if (!same.count(backs[i]))  ans = min(ans, backs[i]);
        }

        return ans == INT_MAX ? 0 : ans;
    }
};