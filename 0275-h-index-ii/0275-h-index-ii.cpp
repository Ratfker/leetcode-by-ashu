class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (citations[n - mid] >= mid) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};