class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0, select=nums.size()/2;
        for(int i=0; i<nums.size(); i++)
            count = count + abs(nums[select]-nums[i]);
        return count;
    }
};
