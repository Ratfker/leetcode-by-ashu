class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n/2; i++) {
            if (i > 1 && num[0] == '0') break;
            for (int j = 1; j <= (n-i)/2 || (j <= n-i && j <= i); j++) {
                if (j > 1 && num[i] == '0') break;
                if (i + j >= n) continue;
                string first = num.substr(0, i);
                string second = num.substr(i, j);
                if (check(num, i+j, first, second)) return true;
            }
        }
        return false;
    }
    
private:
    bool check(const string& num, int start, string first, string second) {
        if (start == num.size()) return true;
        
        string sum = addStrings(first, second);
        int len = sum.size();
        
        if (start + len > num.size()) return false;
        if (num.substr(start, len) != sum) return false;
        
        return check(num, start + len, second, sum);
    }
    
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};