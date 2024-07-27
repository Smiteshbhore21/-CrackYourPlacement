class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,n,0,0, "");
        return res;
    }
    void backtrack(vector<string> &res,int n,int open, int close, string curr_str){
        //base case
        if(curr_str.size()==n*2)
        {
            res.push_back(curr_str);
            return;
        }
        if(open<n)  backtrack(res,n,open+1,close,curr_str+"(");
        if(close<open) backtrack(res,n,open,close+1,curr_str+")");
        return;
    }
};
