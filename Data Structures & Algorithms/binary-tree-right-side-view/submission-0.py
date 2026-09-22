# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = []
        q.append(root)

        res = []
        while q:
            qlen = len(q)
            level = []
            for i in range(qlen):
                node = q.pop(0)
                if node:
                    q.append(node.left)
                    q.append(node.right)
                    level.append(node)
            if level:
                res.append(level[-1].val)

        return res