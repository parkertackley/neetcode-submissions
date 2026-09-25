class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(i, currlist):
            res.append(currlist.copy())
            
            for j in range(i, len(nums)):
                if j > i and nums[j] == nums[j - 1]:
                    continue
                
                currlist.append(nums[j])
                dfs(j + 1, currlist)
                currlist.pop()

        dfs(0, [])
        return res