class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, ch = 0, i = 0, j = cardPoints.size() - 1;
        for (i; i < k; i++)
            lsum += cardPoints[i];
        i--;
        ch = lsum;
        for (j; i >= 0; j--, i--) {
            ch = (ch - cardPoints[i]) + cardPoints[j];
            if (ch > lsum)
                lsum = ch;
        }
        return lsum;
    }
};
