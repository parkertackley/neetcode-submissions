class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top, bottom, row = 0, len(matrix) - 1, 0
        l, r = 0, len(matrix[0]) - 1

        while top <= bottom:
            mid = top + ((bottom - top) // 2)
            if matrix[mid][0] > target:
                bottom = mid - 1
            elif matrix[mid][r] < target:
                top = mid + 1
            else:
                row = mid
                break

        while l <= r:
            mid = l + ((r - l) // 2)
            if matrix[row][mid] > target:
                r = mid - 1
            elif matrix[row][mid] < target:
                l = mid + 1
            else:
                return True
        return False