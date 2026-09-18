class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix[0]) - 1
        top, bottom, row = 0, len(matrix) - 1, 0

        while top <= bottom:
            mid = top + (bottom - top) // 2

            if matrix[mid][n] < target:
                top = mid + 1
            elif matrix[mid][0] > target:
                bottom = mid - 1
            else:
                row = mid
                break
        print(row)
        l, r = 0, len(matrix[0]) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] > target:
                r = mid - 1
            else:
                l = mid + 1

        return False