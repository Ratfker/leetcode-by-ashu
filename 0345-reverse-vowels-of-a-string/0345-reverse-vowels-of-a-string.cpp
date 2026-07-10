class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) l++;
            while (l < r && !isVowel(s[r])) r--;
            if (l < r) {
                swap(s[l], s[r]);
                l++; r--;
            }
        }
        return s;
    }
};