class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0, j = height.size() - 1; i != j;) {
            if (height[i] <= height[j]) {
                if (max < height[i] * (j - i))
                    max = height[i] * (j - i);
                i++;
            } else {
                if (max < height[j] * (j - i))
                    max = height[j] * (j - i);
                j--;
            }
        }
        return max;
    }
};
