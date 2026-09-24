class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def dfs(i, curlist, total):
            if total == target:
                res.append(curlist.copy())
                return

            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j - 1]:
                    continue

                if total + candidates[j] > target:
                    return
                
                curlist.append(candidates[j])
                dfs(j + 1, curlist, total + candidates[j])
                curlist.pop()

        dfs(0, [], 0)
        return res