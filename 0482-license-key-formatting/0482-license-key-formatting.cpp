class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean;
        for (char c : s)
            if (c != '-')
                clean += toupper(c);

        int n = clean.size(), first = n % k;
        string result;

        if (first > 0) {
            result += clean.substr(0, first);
            if (n > first) result += '-';
        }

        for (int i = first; i < n; i += k) {
            result += clean.substr(i, k);
            if (i + k < n) result += '-';
        }

        return result;
    }
};