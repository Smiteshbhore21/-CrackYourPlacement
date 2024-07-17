class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
        {
            if (m.find(target-nums[i]) != m.end() && m.find(target-nums[i])->second != i)
            {
                res.push_back(i);
                res.push_back(m.find(target-nums[i])->second);
                return res;
            }
            m[nums[i]]=i;
        }
            return res;
    }
};
