class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            st1, st2 = heapq.heappop(stones), heapq.heappop(stones)
            if st2 > st1:
                heapq.heappush(stones, st1 - st2)

        return abs(stones[0]) if stones else 0