class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int top = 0, bot = matrix.size() - 1;
        while (top < bot)
        {
            int mid = top + ((bot - top) / 2);
            if (matrix[mid][0] > target)
            {
                bot = mid - 1;
            } else if (matrix[mid][matrix[0].size() - 1] < target)
            {
                top = mid + 1;
            } else
            {
                top = mid;
                break;
            }
        }

        int l = 0, r = matrix[top].size() - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (matrix[top][mid] > target)
            {
                r = mid - 1;
            } else if (matrix[top][mid] < target)
            {
                l = mid + 1;
            } else
            {
                return true;
            }
        }
        return false;
    }
};
