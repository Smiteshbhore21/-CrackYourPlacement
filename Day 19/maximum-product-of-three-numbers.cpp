class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1, j = nums.size() - 3,
            sum = nums[j] * nums[i - 1] * nums[i],
            r2sum = nums[0] * nums[1] * nums[i],
            r1sum = nums[0] * nums[i - 1] * nums[i];
        if (r2sum > sum)
            return r2sum;
        else if (r1sum > sum)
            return r1sum;
        return sum;
    }
};
