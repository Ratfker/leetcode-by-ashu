class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int res = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(dx, dy);
                string slope = to_string(dx/g) + "/" + to_string(dy/g);
                res = max(res, ++mp[slope] + 1);
            }
        }

        return res;
    }
};