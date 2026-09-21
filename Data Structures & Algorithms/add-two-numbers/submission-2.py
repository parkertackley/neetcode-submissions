# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode(0)
        dummy = res

        carry = 0
        while l1 or l2 or carry:
            v1 = 0 if not l1 else l1.val
            v2 = 0 if not l2 else l2.val

            value = v1 + v2 + carry
            carry = value // 10
            digit = value % 10

            dummy.next = ListNode(digit)
            dummy = dummy.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return res.next