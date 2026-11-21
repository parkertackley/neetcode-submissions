# nums = []

# return [x, y, z] where x, y, z are the 3 most frequent numbers in nums

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        mp = defaultdict(int)

        for n in nums:
            mp[n] += 1

        slist = sorted(mp.items(), key=lambda item: item[1], reverse=True)

        res = []
        for key, val in slist:
            if len(res) == k:
                return res
            res.append(key)

        return res