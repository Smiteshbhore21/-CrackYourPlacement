#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
    void Print_all_the_duplicate_characters_in_a_string(string s){
        int n = s.length();
        int h[52]={0};
        for(int i=0;i<n;i++){
            if (s[i]>='a' && s[i]<='z') h[s[i]-'a']++;
            else if (s[i]>='A' && s[i]<='Z') h[s[i]-'A'+27]++;
        }
        for(int i=0;i<52;i++){
            if (h[i]>1 && i<=26) cout<<char(i+'a')<<":"<<h[i]<<endl;
            else if(h[i]>1 && i>=27) cout<<char(i+'A'-27)<<":"<<h[i]<<endl;
        }
    }
};

int main(){
    Solution s;
    s.Print_all_the_duplicate_characters_in_a_string("geeksforgeeks");
    return 0;
}
