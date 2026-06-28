class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }

    void backtrack(string& s, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--]) return false;
        return true;
    }
};