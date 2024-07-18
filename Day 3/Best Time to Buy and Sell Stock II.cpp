class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = prices[0], max = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > start)
                max = max + prices[i] - start;
            start = prices[i];
        }
        return max;
    }
};
