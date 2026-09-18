class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        st = []
        res = 0

        for i in range(len(heights) + 1):

            while st and (i == len(heights) or heights[st[-1]] >= heights[i]):
                height = heights[st.pop()]
                width = i if not st else i - st[-1] - 1
                res = max(res, width * height)

            st.append(i)    
        return res
