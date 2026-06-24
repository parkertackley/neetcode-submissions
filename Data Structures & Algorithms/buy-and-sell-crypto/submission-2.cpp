class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int res = 0;

        for (const int& sell : prices)
        {
            minbuy = min(minbuy, sell);
            res = max(res, sell - minbuy);
        }
        return res;
    }
};
