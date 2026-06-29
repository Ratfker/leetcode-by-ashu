class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word)
            words.push_back(word);

        reverse(words.begin(), words.end());

        string res;
        for (int i = 0; i < words.size(); i++) {
            if (i) res += " ";
            res += words[i];
        }

        return res;
    }
};