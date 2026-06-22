class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (A.size() > B.size())
        {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int j = half - mid;

            int Aleft = mid > 0 ? A[mid - 1] : INT_MIN;
            int Aright = mid < A.size() ? A[mid] : INT_MAX;

            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if (total % 2 != 0)
                {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright)
            {
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};
