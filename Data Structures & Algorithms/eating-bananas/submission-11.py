class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)    # start at 1 bc speed of 0 cant happen, fastest speed is eating the largest pile in one hour

        while l < r:
            speed = l + ((r - l) // 2)  # find middle speed

            time = 0
            for pile in piles:  # calculate time it takes to eat all piles
                time += math.ceil((pile / speed))   # ceil bc we cant start a new pile within the same hour
            
            if time > h:    # if time to eat greater that time available, we speed up the eating
                l = speed + 1
            else:           # else we can slow the eating until we get to the minium speed
                r = speed

        return l