class Solution {
public:
    bool isNumber(string s) {
        bool hasNum = false, hasDot = false, hasE = false, hasSign = false;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                hasNum = true;
            } else if (c == '+' || c == '-') {
                if (i != 0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
            } else if (c == '.') {
                if (hasDot || hasE)
                    return false;
                hasDot = true;
            } else if (c == 'e' || c == 'E') {
                if (hasE || !hasNum)
                    return false;
                hasE = true;
                hasNum = false;
            } else {
                return false;
            }
        }
        
        return hasNum;
    }
};