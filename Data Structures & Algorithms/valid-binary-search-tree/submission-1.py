# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        q = []
        q.append((root, float("-inf"), float("inf")))

        while q:
            node, leftmax, rightmin = q.pop(0)
            if not (leftmax < node.val < rightmin):
                return False
            if node.left:
                q.append((node.left, leftmax, node.val))
            if node.right:
                q.append((node.right, node.val, rightmin))

        return True