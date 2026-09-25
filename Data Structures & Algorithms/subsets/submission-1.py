class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]] # [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]

        for num in nums:
            res += [subset + [num] for subset in res]

        return res
        