class Solution {
public:
    map<tuple<string,string>, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;

        auto key = make_tuple(s1, s2);
        if (memo.count(key)) return memo[key];

        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) return memo[key] = false;

        int n = s1.size();
        for (int i = 1; i < n; i++) {
            // No swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return memo[key] = true;

            // Swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }
};