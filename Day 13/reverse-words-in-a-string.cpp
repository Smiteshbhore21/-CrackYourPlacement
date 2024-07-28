class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=0, n=s.length(), j=0;
        while(i<n){
            while(i<n && s[i]==' ')i++;
            if(i>=n) break;
            j=i+1;
            while(j<n && s[j]!= ' ')j++;
            string sub=s.substr(i,j-i);
            if(ans.length()==0) ans=sub;
            else ans = sub+" "+ans;
            i=j+1;
        }
        return ans;
        /*USING STACK*/
        // stack<string> st;
        // string word = "";
        // string result = "";
        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] == ' ') {
        //         if (!word.empty()) {
        //             st.push(word);
        //             word = "";
        //         }
        //     } else {
        //         word += s[i];
        //     }
        // }
        // if (!word.empty()) {
        //     st.push(word);
        // }
        // while (st.size() != 1) {
        //     result += st.top() + " ";
        //     st.pop();
        // }
        // result += st.top();
        // return result;
    }
};
