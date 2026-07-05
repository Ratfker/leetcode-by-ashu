class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        vector<int> s = {1, 2, 2};
        int head = 2, next = 1;

        while ((int)s.size() < n) {
            int cnt = s[head++];
            for (int i = 0; i < cnt && (int)s.size() < n; i++)
                s.push_back(next);
            next = 3 - next;
        }

        return count(s.begin(), s.begin() + n, 1);
    }
};