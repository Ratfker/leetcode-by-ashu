class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        unordered_set<string> current;
        current.insert(s);
        visited.insert(s);
        
        while (true) {
            for (const string& str : current) {
                if (isValid(str)) {
                    vector<string> result(current.begin(), current.end());
                    vector<string> validResults;
                    for (auto& r : current) {
                        if (isValid(r)) validResults.push_back(r);
                    }
                    return validResults;
                }
            }
            
            unordered_set<string> next;
            for (const string& str : current) {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] != '(' && str[i] != ')') continue;
                    string next_str = str.substr(0, i) + str.substr(i+1);
                    if (visited.find(next_str) == visited.end()) {
                        visited.insert(next_str);
                        next.insert(next_str);
                    }
                }
            }
            
            if (next.empty()) {
                return {""};
            }
            
            current = next;
        }
    }
    
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
};