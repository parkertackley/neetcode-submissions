# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0
        def dfs(node, maxval):
            nonlocal res
            if not node:
                return 0
            
            highest = max(maxval, node.val)

            if node.val >= maxval:
                return 1 + dfs(node.left, highest) + dfs(node.right, highest)

            return dfs(node.left, highest) + dfs(node.right, highest)

        return dfs(root, -101)