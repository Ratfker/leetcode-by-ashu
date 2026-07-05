class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % n != 0) return -1;
        int avg = sum / n;
        int result = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            int diff = machines[i] - avg;
            prefix += diff;
            result = max(result, max(abs(prefix), diff));
        }
        return result;
    }
};