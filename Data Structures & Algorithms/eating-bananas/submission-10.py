class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)

        while l < r:
            speed = l + ((r - l) // 2)

            time = 0
            for pile in piles:
                time += math.ceil((pile / speed))
            
            if time > h:
                l = speed + 1
            else:
                r = speed

        return l