class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, i = 1, size=nums.size();
        for (i; i < size; i++) {
            if (nums[i] != nums[i - 1]) nums[j++] = nums[i];
        }
        return j;
    }
};
