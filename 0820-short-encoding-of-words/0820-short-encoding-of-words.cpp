class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (const string& w : words)
            for (int i = 1; i < w.size(); i++)
                s.erase(w.substr(i));

        int ans = 0;
        for (const string& w : s)
            ans += w.size() + 1;
        return ans;
    }
};