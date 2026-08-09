class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> st;
        int i = 0, n = s.size();

        while (i < n) {
            char c = s[i];

            if (c == '[') {
                st.push(NestedInteger());
                i++;
            }
            else if (c == ',') {
                i++;
            }
            else if (c == ']') {
                NestedInteger closed = st.top();
                st.pop();
                if (!st.empty()) {
                    st.top().add(closed);
                } else {
                    return closed;
                }
                i++;
            }
            else {
                int j = i;
                while (j < n && s[j] != ',' && s[j] != ']') j++;
                int val = stoi(s.substr(i, j - i));
                st.top().add(NestedInteger(val));
                i = j;
            }
        }
        return st.top();
    }
};