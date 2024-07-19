class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size()-1, j = 0;
        if (m==0)
            nums1.clear();
        else {
            while (nums1[i] == 0 && i!=m-1)
                nums1.erase(nums1.begin() + i--);
        }
        i=0;
        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] <= nums2[j])
                i++;
            else
                nums1.insert(nums1.begin() + i++, nums2[j++]);
        }
        while (j != nums2.size())
            nums1.insert(nums1.begin() + i++, nums2[j++]);
    }
};
