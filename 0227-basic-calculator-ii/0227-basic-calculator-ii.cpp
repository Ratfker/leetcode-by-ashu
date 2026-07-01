class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); i++) {
            if (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if (i == s.size() || (!isdigit(s[i]) && s[i] != ' ')) {
                if (op == '+')
                    st.push(num);
                else if (op == '-')
                    st.push(-num);
                else if (op == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                } else if (op == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }

                if (i < s.size())
                    op = s[i];
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};