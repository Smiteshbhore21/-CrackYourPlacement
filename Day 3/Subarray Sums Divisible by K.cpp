class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ////Brute Approuch
        // int sum=0, count=0;
        // for (int i=0; i<nums.size(); i++)
        // {
        //     sum=0;
        //     for (int j=i; j<nums.size(); j++)
        //     {
        //         sum+=nums[j];
        //         if (sum%k==0)
        //             count++;
        //     }
        // }
        // return count;
        unordered_map<int, int> m;
        int sum = 0, count = 0, rem = 0, i = 0;
        m[rem]++;
        for (i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rem = sum % k;
            if (rem < 0)    rem = rem % k + k;
            if (m.find(rem) != m.end()) count += m.at(rem);
            m[rem]++;
        }
        return count;
    }
};
