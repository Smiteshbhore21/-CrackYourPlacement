class Solution {
public:
    void sortColors(vector<int>& nums) {
        int h[3] = {0};
        for (int i = 0; i < nums.size(); i++)
            h[nums[i]]++;
        int sum = h[0];
        for (int i = 0, j = 0; i < nums.size();) {
            if (i != sum) nums[i++] = j;
            else {
                j++;
                sum += h[j];
            }
        }
    }
};
