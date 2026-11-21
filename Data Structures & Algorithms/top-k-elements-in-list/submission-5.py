# nums = [1, 2, 3, 3, 3, 4, 5, 5] k = 2

# res = [3, 5] | [5, 3]

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for n in nums:
            count[n] = 1 + count.get(n, 0)
        
        freq = [[] for _ in range(len(nums) + 1)]
        for key, val in count.items():
            freq[val].append(key)

        res = []
        for num in range(len(freq) - 1, 0, -1):
            for entry in freq[num]:
                res.append(entry)
                if len(res) == k:
                    return res

        return res