class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l <= r) {
            int mid = l +((r - l) / 2);
            double time = 0;
            for(const int& p : piles) {
                time += ceil(static_cast<double>(p) / mid);
            }
            if(time <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;

    }
};
