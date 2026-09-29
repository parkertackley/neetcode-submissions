class Solution:
    def isHappy(self, n: int) -> bool:

        def sumofdigits(num: int) -> int:
            res = 0
            while num > 0:
                res += (num % 10) ** 2
                num //= 10
            return res

        visit = set()
        while n not in visit:
            visit.add(n)
            n = sumofdigits(n)
            if n == 1:
                return True
        return False
        
    