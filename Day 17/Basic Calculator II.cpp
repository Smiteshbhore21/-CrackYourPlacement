class Solution {
public:
    int calculate(string s) {
        if (s.length()==0) return 0;
        stack<int> st;
        long int curr=0;
        char op = '+';
        for (int i=0; i<s.length();i++){
            if(isdigit(s[i])){
                curr=curr*10+s[i]-'0';
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i == s.length()-1){
                if(op=='+'){
                    st.push(curr);
                }
                else if(op=='-'){
                    st.push(-curr);
                }
                else if(op=='*'){
                    long int ch=st.top()*curr;
                    st.pop();
                    st.push(ch);
                }
                else if(op=='/'){
                    long int ch=st.top()/curr;
                    st.pop();
                    st.push(ch);
                }
                op=s[i];
                curr=0;
            }
        }
        long int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
