class Solution {
public:
    int climbStairs(int n) {
        int curr=1, prev=0, res=0;
        for(int i=0; i<n; i++){
            res=curr+prev;
            prev=curr;
            curr=res;
        }
        return res;
    }
};
