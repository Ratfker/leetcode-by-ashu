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
    
    int findLUSlength(vector<string>& strs) {
        int result = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool isUncommon = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) result = max(result, (int)strs[i].size());
        }
        return result;
    }
};