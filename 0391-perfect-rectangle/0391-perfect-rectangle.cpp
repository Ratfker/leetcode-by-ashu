class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> st;
        int minX = INT_MAX, minY = INT_MAX, maxA = INT_MIN, maxB = INT_MIN;
        long long area = 0;

        for (auto& r : rectangles) {
            int x = r[0], y = r[1], a = r[2], b = r[3];
            minX = min(minX, x); minY = min(minY, y);
            maxA = max(maxA, a); maxB = max(maxB, b);
            area += (long long)(a - x) * (b - y);

            vector<pair<int,int>> corners = {{x,y},{x,b},{a,y},{a,b}};
            for (auto& c : corners) {
                if (st.count(c)) st.erase(c);
                else st.insert(c);
            }
        }

        long long expectedArea = (long long)(maxA - minX) * (maxB - minY);
        if (area != expectedArea) return false;
        if (st.size() != 4) return false;
        if (!st.count({minX, minY})) return false;
        if (!st.count({minX, maxB})) return false;
        if (!st.count({maxA, minY})) return false;
        if (!st.count({maxA, maxB})) return false;
        return true;
    }
};