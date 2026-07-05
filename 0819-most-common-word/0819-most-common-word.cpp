class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> cnt;

        for (auto& c : paragraph)
            c = isalpha(c) ? tolower(c) : ' ';

        istringstream iss(paragraph);
        string word;
        while (iss >> word)
            if (!ban.count(word))
                cnt[word]++;

        return max_element(cnt.begin(), cnt.end(),
            [](auto& a, auto& b){ return a.second < b.second; })->first;
    }
};