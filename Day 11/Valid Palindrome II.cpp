class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        for (i, j; i <= j; i++, j--) {
            if (s[i] != s[j])
                return Palindrome(s, i + 1, j) || Palindrome(s, i, j - 1);
        }
        return true;
    }
    bool Palindrome(string, int, int);
};

bool Solution::Palindrome(string st, int i, int j) {
    for (i, j; i <= j; i++, j--) {
        if (st[i] != st[j])
            return false;
    }
    return true;
}
