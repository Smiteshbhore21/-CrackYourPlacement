class Solution {
    public int strStr(String haystack, String needle) {
        for(int i=0; i<haystack.length();i++){
            if (haystack.charAt(i)==needle.charAt(0)){
                int j=1, ch=i+1;
                boolean as=true;
                while(as && ch<haystack.length())
                {
                    if (j!=needle.length()  &&  haystack.charAt(ch)==needle.charAt(j)){
                        ch++;
                        j++;
                    }
                    else as=false;
                }
                if (j==needle.length()) return i;
            }
        }
        return -1;
    }
}
