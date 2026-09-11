class Solution:
    def isValid(self, s: str) -> bool:
        mp = {")": "(", "}": "{", "]": "["}

        stack = []
        for paren in s:
            if paren in mp:
                if stack and mp[paren] == stack[-1]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(paren)

        return len(stack) == 0
