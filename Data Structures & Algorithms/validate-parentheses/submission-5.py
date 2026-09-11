class Solution:
    def isValid(self, s: str) -> bool:
        mp = {")": "(", "}": "{", "]": "["}

        stack = []
        for paren in s:
            if paren in mp:
                if len(stack) > 0 and mp[paren] == stack[-1]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(paren)
            print(stack)

        return len(stack) == 0
