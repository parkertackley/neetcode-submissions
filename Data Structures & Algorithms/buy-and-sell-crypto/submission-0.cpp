class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice = 0;
        int minBuy = prices[0];

        for (const int& sell : prices)
        {
            maxPrice = max(maxPrice, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxPrice;
    }
};
