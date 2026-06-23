class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;

        // need to run until AFTER the last element to
        // check that it doesnt make up the largest rectangle
        for (int i = 0; i <= heights.size(); i++)
        {
            while (!st.empty() && 
            (i == heights.size() || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width = (st.empty()) ? i : i - st.top() - 1;
                res = max(res, width * height);
            }
            st.push(i);
        }
        return res;
    }
};
