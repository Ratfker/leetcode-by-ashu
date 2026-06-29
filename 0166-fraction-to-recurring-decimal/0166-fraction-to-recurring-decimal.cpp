class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result = "";

        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        result += to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0) return result;

        result += ".";

        unordered_map<long long, int> remainderMap;
        string frac = "";

        while (remainder != 0) {
            if (remainderMap.count(remainder)) {
                frac.insert(remainderMap[remainder], "(");
                frac += ")";
                break;
            }

            remainderMap[remainder] = frac.size();
            remainder *= 10;
            frac += to_string(remainder / den);
            remainder %= den;
        }

        return result + frac;
    }
};