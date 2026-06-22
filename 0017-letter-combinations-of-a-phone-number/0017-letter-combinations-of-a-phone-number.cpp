class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result = {""};
        for (char d : digits) {
            vector<string> temp;
            for (string& combo : result)
                for (char c : phone[d - '2'])
                    temp.push_back(combo + c);
            result = temp;
        }
        return result;
    }
};