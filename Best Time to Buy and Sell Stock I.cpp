class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int res = 0;
        int minp = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            minp = min(minp, prices[i]);
            res = max(res, prices[i] - minp);
        }
        return res;
    }
};