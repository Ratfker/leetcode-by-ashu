class Solution {
public:
    int guessNumber(int n) {
        long long low = 1, high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int res = guess((int)mid);
            if (res == 0) return (int)mid;
            else if (res < 0) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};