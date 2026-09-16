class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        res = 0

        l = 0   # left pointer
        maxf = 0    # count of the most common letter in the current window
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)    # increment the count of the right pointers character
            maxf = max(maxf, count[s[r]])   # get the count of the most frequent character in the window

            while (r - l + 1) - maxf > k:   # checks that the number of characters to be changed is > k
                count[s[l]] -= 1    # incrementing the left pointer, so we adjust the count of its characters in the current window
                l += 1

            res = max(res, r - l + 1)   # update result with the current window size
        return res