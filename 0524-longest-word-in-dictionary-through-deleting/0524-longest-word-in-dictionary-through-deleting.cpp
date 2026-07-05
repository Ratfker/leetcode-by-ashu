class Solution {
public:
    bool isSubsequence(string& a, string& b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        string result = "";
        for (string& word : dictionary) {
            if (isSubsequence(word, s)) {
                if (word.size() > result.size() || (word.size() == result.size() && word < result)) {
                    result = word;
                }
            }
        }
        return result;
    }
};