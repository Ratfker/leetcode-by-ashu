class Solution {
public:
    bool canForm(const string& word, unordered_set<string>& wordSet) {
        int n = word.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && j > 0 && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
                if (dp[j] && j == 0 && i < n && wordSet.count(word.substr(0, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        for (const string& word : words) {
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            int pieces = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (!dp[j]) continue;
                    string sub = word.substr(j, i - j);
                    if (sub == word) continue;
                    if (wordSet.count(sub)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n]) result.push_back(word);
        }
        return result;
    }
};