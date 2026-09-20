class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0 for _ in range(len(temperatures))]

        st = []
        for i, temp in enumerate(temperatures):
            while st and temp > st[-1][1]:
                sidx, stemp = st.pop()
                res[sidx] = i - sidx
            st.append((i, temp))
            
        return res