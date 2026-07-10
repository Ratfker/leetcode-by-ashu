class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        backtrack(num, target, 0, 0, 0, path, res);
        return res;
    }

    void backtrack(const string& num, int target, int idx, long long curr, long long prev, string& path, vector<string>& res) {
        int n = num.size();
        if (idx == n) {
            if (curr == target) res.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (i != idx && num[idx] == '0') break;
            string part = num.substr(idx, i - idx + 1);
            long long val = stoll(part);
            int len = path.size();

            if (idx == 0) {
                path += part;
                backtrack(num, target, i + 1, val, val, path, res);
                path.resize(len);
            } else {
                path += "+" + part;
                backtrack(num, target, i + 1, curr + val, val, path, res);
                path.resize(len);

                path += "-" + part;
                backtrack(num, target, i + 1, curr - val, -val, path, res);
                path.resize(len);

                path += "*" + part;
                backtrack(num, target, i + 1, curr - prev + prev * val, prev * val, path, res);
                path.resize(len);
            }
        }
    }
};