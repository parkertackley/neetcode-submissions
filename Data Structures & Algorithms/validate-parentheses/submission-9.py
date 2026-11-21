class Solution:
    def isValid(self, s: str) -> bool:
        mp = {
            ")": "(",
            "]": "[",
            "}": "{"
        }

        st = []
        for c in s:
            if c in mp and st:
                top = st.pop()
                if mp[c] != top:
                    return False
            else:
                st.append(c)
        
        return len(st) == 0