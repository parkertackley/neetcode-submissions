class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 0, r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int mid = l + ((r - l) / 2);

            double time = 0;
            for (const int& i : piles) {
                time += ceil((double) i / mid);
            }
            if (time <= h) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
