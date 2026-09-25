class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        used = [False for _ in range(len(nums))]

        def dfs(i, currlist):
            if len(currlist) == len(nums):
                res.append(currlist.copy())
                return

            for i in range(len(nums)):
                if used[i]:
                    continue

                used[i] = True
                currlist.append(nums[i])
                dfs(i, currlist)
                used[i] = False
                currlist.pop()            

        dfs(0, [])
        return res