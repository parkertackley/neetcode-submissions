class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(i, currlist, total):
            if total == target:
                res.append(currlist.copy())
                return
            
            for j in range(i, len(nums)):
                if total + nums[j] > target:
                    return

                currlist.append(nums[j])
                dfs(j, currlist, total + nums[j])
                currlist.pop()
                

        dfs(0, [], 0)
        return res