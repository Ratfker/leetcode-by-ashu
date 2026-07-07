class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1; 
        
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            
            if (digit != 0) 
            {
                
                x = x + (digit * multiplier);
                sum += digit;
                multiplier *= 10;
            }
        }
        
        return x * sum;
    }
};