class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0, formed = 0;
        int required = need.size();
        int minLen = INT_MAX, minStart = 0;

        while (right < s.size()) {
            char c = s[right++];
            window[c]++;
            if (need.count(c) && window[c] == need[c])
                formed++;

            while (formed == required) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }
                char lc = s[left++];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc])
                    formed--;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};