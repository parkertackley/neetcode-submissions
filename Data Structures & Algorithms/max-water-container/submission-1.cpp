class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxVol = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r)
        {
            int height = min(heights[l], heights[r]);
            maxVol = max(maxVol, height * (r - l));
            if (heights[l] > heights[r])
            {
                r--;
            } else
            {
                l++;
            }
        }
        return maxVol;
    }
};
