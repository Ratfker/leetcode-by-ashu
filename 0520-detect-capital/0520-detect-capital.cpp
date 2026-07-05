class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upperCount = 0;
        for (char c : word) {
            if (isupper(c)) upperCount++;
        }
        if (upperCount == 0 || upperCount == n) return true;
        if (upperCount == 1 && isupper(word[0])) return true;
        return false;
    }
};