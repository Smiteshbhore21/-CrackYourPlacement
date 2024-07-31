#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rabin_karp_algorithm_for_pattern_searching(string pat, string txt) {
        vector<int> res;
        int M = txt.length();
        int N = pat.length();
        int p = 0; // hash value for pattern
        int t = 0; // hash value for txt
        int h = 1;
        int d = 256; // number of characters in the input alphabet
        int q = 101; // a prime number

        // The value of h would be "pow(d, M-1)%q"
        for (int i = 0; i < M-1; i++)
            h = (h*d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < M; i++) {
            p = (d*p + txt[i]) % q;
            t = (d*t + pat[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= N - M; i++) {
            // Check the hash values of current window of text and pattern
            if ( p == t ) {
                bool flag = true;
                for (int j = 0; j < M; j++) {
                    if (pat[i + j] != txt[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    res.push_back(i);
            }

            // Calculate hash value for next window of text: Remove leading digit, add trailing digit
            if ( i < N - M ) {
                t = (d*(t - txt[0]*h) + pat[i + M]) % q;
                if (t < 0)
                t = (t + q);
            }
        }

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
};

int main() {
    Solution s;
    string pat = "abcabcabc";
    string txt = "abc";
    s.rabin_karp_algorithm_for_pattern_searching(pat, txt);
    return 0;
}
