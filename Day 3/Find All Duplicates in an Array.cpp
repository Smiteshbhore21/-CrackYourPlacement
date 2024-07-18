class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // vector<int> res;
        // for (int i=1; i<nums.size(); i++)
        // {
        //     if (nums[i-1]==nums[i])
        //     {
        //         res.push_back(nums[i]);
        //         nums[i]=-1;
        //     }
        // }
        // return res;
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (max < nums[i])
                max = nums[i];
        }
        vector<int> h(max + 1, 0), res;
        for (int i = 0; i < nums.size(); i++)
            h[nums[i]]++;
        for (int i = 0; i < nums.size(); i++) {
            if (h[nums[i]] >= 2) {
                h[nums[i]] = 0;
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
