class Solution {
public:
    int count = 0;
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        backtrack(1, n, used);
        return count;
    }
    
    void backtrack(int pos, int n, vector<bool>& used) {
        if (pos > n) {
            count++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                backtrack(pos + 1, n, used);
                used[i] = false;
            }
        }
    }
};