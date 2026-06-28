class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> backtrack(const string& s, int start) {
        if (memo.count(start)) return memo[start];
        if (start == s.size()) return {""};

        vector<string> res;
        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                for (string& rest : backtrack(s, end)) {
                    res.push_back(word + (rest.empty() ? "" : " " + rest));
                }
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return backtrack(s, 0);
    }
};