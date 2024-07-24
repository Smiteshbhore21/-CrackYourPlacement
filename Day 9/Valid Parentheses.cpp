class Solution {
public:
    char perVal(char);
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == '{') || (s[i] == '[') || (s[i] == '('))
                st.push(s[i]);
            else {
                if (st.empty() != 1) {
                    if (st.top() == perVal(s[i])) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

char Solution::perVal(char s) {
    switch (s) {
    case ')':
        return '(';
    case '}':
        return '{';
    case ']':
        return '[';
    }
    return '0';
}
