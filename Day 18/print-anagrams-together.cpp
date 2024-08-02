class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>> m;
        for(int i=0; i<string_list.size(); i++){
            string s=string_list[i];
            sort(s.begin(), s.end());
            m[s].push_back(string_list[i]);
        }
        int idx=0;
        vector<vector<string>> ans(m.size());
        for(auto x:m){
            auto v=x.second;
            for (int i=0; i<v.size(); i++){
                ans[idx].push_back(v[i]);
            }
            idx++;
        }
        
        return ans;
    }
};
