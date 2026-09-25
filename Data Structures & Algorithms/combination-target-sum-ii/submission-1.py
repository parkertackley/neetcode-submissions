class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def dfs(i, currlist, total):
            if total == target:
                res.append(currlist.copy())
                return

            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue
                
                if total + candidates[j] > target:
                    return

                currlist.append(candidates[j])
                dfs(j + 1, currlist, total + candidates[j])
                currlist.pop()

        dfs(0, [], 0)
        return res