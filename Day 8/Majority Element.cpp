class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for (int i=0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for (auto it : mp)
        // {
        //     if (it.second > nums.size()/2) return it.first;
        // }
        // return -1;
        int elem = nums[0], count = 0, cnt=0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                elem = nums[i];
                count = 1;
            } else if (elem == nums[i])
                count++;
            else
                count--;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == elem)
                cnt++;
        }
        if (cnt > nums.size() / 2)
            return elem;
        return -1;
    }
};
