class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp=matrix;
        int n = temp.size()-1, m=0;
        int size = n;
        int size2 = temp[0].size()-1;
        for(int i=0; i<=size; i++){
            for(int j=0; j<=size2; j++){
                matrix[i][j] = temp[n--][m];
            }
            n=size;
            m++;
        }
    }
};
