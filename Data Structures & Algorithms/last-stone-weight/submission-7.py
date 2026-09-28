class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxheap = [-stone for stone in stones]
        heapq.heapify(maxheap)

        while len(maxheap) > 1:
            x = heapq.heappop(maxheap)
            y = heapq.heappop(maxheap)

            if x == y:
                continue
            heapq.heappush(maxheap, x - y)
        
        return 0 if len(maxheap) == 0 else abs(maxheap[0])