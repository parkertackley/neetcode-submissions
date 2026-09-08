class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int l = 0;
        int r = heights.size() - 1;
        int vol = 0;

        while(l < r) {
            int lower = (heights[l] > heights[r]) ? heights[r] : heights[l];
            int diff = r - l;

            if(diff * lower > vol) {
                vol = diff * lower;
            }

            if(heights[l] > heights[r]) {
                --r; 
            } else {
                ++l;
            }

        }

        return vol;

    }
};
