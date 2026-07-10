class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        int n = words.size();
        for (int i = 0; i < n; i++) mp[words[i]] = i;

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            string w = words[i];
            int len = w.size();
            for (int j = 0; j <= len; j++) {
                string left = w.substr(0, j);
                string right = w.substr(j);

                if (isPalindrome(left)) {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    auto it = mp.find(revRight);
                    if (it != mp.end() && it->second != i) {
                        res.push_back({it->second, i});
                    }
                }

                if (j != len && isPalindrome(right)) {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    auto it = mp.find(revLeft);
                    if (it != mp.end() && it->second != i) {
                        res.push_back({i, it->second});
                    }
                }
            }
        }
        return res;
    }

private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};