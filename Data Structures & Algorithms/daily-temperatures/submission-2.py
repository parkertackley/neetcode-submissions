class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        res = [0 for _ in range(len(temperatures))]

        for i, temp in enumerate(temperatures):
            while st and temp > st[-1][0]:
                stemp, sidx = st.pop()
                res[sidx] = i - sidx
            st.append((temp, i))
        return res