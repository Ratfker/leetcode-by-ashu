class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1000000007;
        int m = r - l + 1;
        
        vector<long long> dpUp(m), dpDown(m);
        vector<long long> prefUp(m), prefDown(m);
        vector<long long> newUp(m), newDown(m);
        
        for (int idx = 0; idx < m; ++idx) {
            int v = l + idx;
            dpUp[idx] = (long long)(v - l) % MOD;
            dpDown[idx] = (long long)(r - v) % MOD;
        }
        
        for (int step = 3; step <= n; ++step) {
            prefUp[0] = dpUp[0];
            prefDown[0] = dpDown[0];
            for (int i = 1; i < m; ++i) {
                prefUp[i] = (prefUp[i-1] + dpUp[i]) % MOD;
                prefDown[i] = (prefDown[i-1] + dpDown[i]) % MOD;
            }
            
            long long totalUp = prefUp[m-1];
            
            for (int idx = 0; idx < m; ++idx) {
                long long sumGreaterUp = (totalUp - prefUp[idx] + MOD) % MOD;
                newDown[idx] = sumGreaterUp;
                
                long long sumLessDown = (idx == 0) ? 0 : prefDown[idx-1];
                newUp[idx] = sumLessDown;
            }
            
            // swap instead of reallocating
            swap(dpUp, newUp);
            swap(dpDown, newDown);
        }
        
        long long ans = 0;
        for (int idx = 0; idx < m; ++idx) {
            ans = (ans + dpUp[idx] + dpDown[idx]) % MOD;
        }
        
        return (int)ans;
    }
};