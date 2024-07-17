class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], max = 0, i = 1;
        for (i; i < prices.size(); i++) {
            if (min > prices[i])    min = prices[i];
            else if (prices[i] - min > max) max = prices[i] - min;
        }
        return max;
    }
};
