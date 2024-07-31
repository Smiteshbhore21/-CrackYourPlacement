#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rabin_karp_algorithm_for_pattern_searching(string pat, string txt) {
        // int m = pat.length();
        // int n = txt.length();
        // int hashc=0, hasht=0;
        // int h = 1;
        // for (int i=0; i<m; i++)
        //     hasht += pat[i];

        // for (int i=0; i<m-1; i++)
        //     hashc += txt[i];

        // vector<int> res;
        
        // for (int i=0, j=m-1; j<n; j++, i++){
        //     hashc=hashc+txt[j];
        //     if(hasht==hashc){
        //         h=1;
        //         for (int k=i, l=0; k<m ;k++,l++){
        //             if(pat[l]!=txt[k]) h=0;
        //         }
        //         if(h==1)    res.push_back(i);
        //     }
        //     hashc=hashc-txt[i];
        // }
        
        // for (int i=0; i<res.size(); i++){
        //     cout << res[i] << " ";
        // }
        
        vector<int> res;
        int M = txt.length();
        int N = pat.length();
        int p = 0; 
        int t = 0; 
        int h = 1;
        int d = 256;
        int q = 101; 

        for (int i = 0; i < M-1; i++)
            h = (h*d) % q;

        for (int i = 0; i < M; i++) {
            p = (d*p + txt[i]) % q;
            t = (d*t + pat[i]) % q;
        }

        for (int i = 0; i <= N - M; i++) {
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
