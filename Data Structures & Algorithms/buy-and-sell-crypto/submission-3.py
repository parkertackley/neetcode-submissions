class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minbuy, res = prices[0], 0

        for i, n in enumerate(prices):
            minbuy = min(minbuy, n)
            res = max(res, n - minbuy)

        return res