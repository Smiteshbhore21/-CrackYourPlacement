class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int siz=nums.size();
        if (siz==0) return 0;
        int h[siz];
        for (int i=0; i<siz; i++)
            h[i]=0;
        for (int i=0; i<siz; i++)
        {
            h[nums[i]]++;
            if (h[nums[i]]>1)
                return nums[i];
        }
        return 0;
    }
};
