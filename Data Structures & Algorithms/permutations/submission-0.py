class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(i, currlist):
            if len(currlist) == len(nums):
                res.append(currlist.copy())
                return

            for i, num in enumerate(nums):
                if num in currlist:
                    continue

                currlist.append(num)
                dfs(i, currlist)
                currlist.pop()            

        dfs(0, [])
        return res