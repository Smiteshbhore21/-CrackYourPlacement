class Solution {
public:
    string intToRoman(int num) {
        vector<int> intCode = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> code = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        for(int i=0;i<intCode.size();i++){
            while(num>=intCode[i]){
                res+=code[i];
                num-=intCode[i];
            }
        }
        return res;
    }
};
