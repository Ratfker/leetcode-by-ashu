class Solution {
    int m, n, total;
    unordered_map<int,int> mp;
public:
    Solution(int m, int n) : m(m), n(n), total(m * n) {}
    
    vector<int> flip() {
        int r = rand() % total;
        total--;
        int x = mp.count(r) ? mp[r] : r;
        mp[r] = mp.count(total) ? mp[total] : total;
        return {x / n, x % n};
    }
    
    void reset() {
        total = m * n;
        mp.clear();
    }
};