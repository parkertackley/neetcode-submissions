class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        eud = []
        heapq.heapify(eud)
        for x, y in points:
            dist = -math.sqrt(x**2 + y**2)
            heapq.heappush(eud, [dist, x, y])
            if len(eud) > k:
                heapq.heappop(eud)
        
        res = []
        while eud:
            dist, x, y = heapq.heappop(eud)
            res.append([x, y])

        return res