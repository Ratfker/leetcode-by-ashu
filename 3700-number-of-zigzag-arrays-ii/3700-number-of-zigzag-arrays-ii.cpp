class Solution {
public:
    static const long long MOD = 1000000007;

    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiplyMatVec(const vector<vector<long long>>& A, const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    long long zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<long long> base(sz, 0);

        for (int v = 0; v < m; v++) {
            base[v] = v;
            base[m + v] = m - 1 - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : base) ans = (ans + x) % MOD;
            return ans;
        }

        vector<vector<long long>> M(sz, vector<long long>(sz, 0));

        for (int v = 0; v < m; v++) {
            for (int u = 0; u < v; u++) {
                M[v][m + u] = 1;
            }
        }

        for (int v = 0; v < m; v++) {
            for (int u = v + 1; u < m; u++) {
                M[m + v][u] = 1;
            }
        }

        long long p = n - 2;

        vector<vector<long long>> R(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) R[i][i] = 1;

        while (p) {
            if (p & 1) R = multiply(R, M);
            M = multiply(M, M);
            p >>= 1;
        }

        vector<long long> finalState = multiplyMatVec(R, base);

        long long ans = 0;
        for (auto x : finalState) ans = (ans + x) % MOD;
        return ans;
    }
};