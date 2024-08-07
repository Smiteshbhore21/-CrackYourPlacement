//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        set<vector<int>> s;
        s.insert(arr);
        while(next_permutation(arr.begin(),arr.end())){
            s.insert(arr);
        }
        for(auto x: s){
            ans.push_back(x);
        }

//Brute Approach
// int i=n-2;
//         while(arr[i]<arr[i+1]){
//             if (i==-1){
//                 i=n-2;
//             }
//             else{
//                 int temp=arr[i];
//                 arr[i]=arr[i+1];
//                 arr[i+1]=temp;
//                 s.insert(arr);
//                 i--;
//             }
//         }
        
//         for(auto x: s){
//             ans.push_back(x);
//         }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
