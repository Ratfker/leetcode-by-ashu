class Solution {
public:
    bool isStretchy(const string& s, const string& w) {
        int i = 0, j = 0, n = s.size(), m = w.size();
        while (i < n && j < m) {
            if (s[i] != w[j]) return false;
            int cnt1 = 1, cnt2 = 1;
            while (i + cnt1 < n && s[i + cnt1] == s[i]) cnt1++;
            while (j + cnt2 < m && w[j + cnt2] == w[j]) cnt2++;
            if (cnt1 != cnt2 && (cnt1 < 3 || cnt1 < cnt2)) return false;
            i += cnt1;
            j += cnt2;
        }
        return i == n && j == m;
    }

    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (const string& w : words)
            if (isStretchy(s, w)) ans++;
        return ans;
    }
};