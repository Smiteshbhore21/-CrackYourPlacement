#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool permut(vector<int>  a, vector<int> b, int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0, j=b.size()-1; i<a.size(); i++, j--)
        if (a[i]+b[j]<k)
        return false;
    return true;
}

int main(){
    vector<int> a={1, 2, 2, 1}, b={3, 3, 3, 4};
    if(permut(a,b,5))
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
