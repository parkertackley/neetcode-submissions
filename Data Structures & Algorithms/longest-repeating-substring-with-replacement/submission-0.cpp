class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, mfreq = 0, res = 0;
        unordered_map<char, int> count;

        for (int r = 0; r < s.size(); r++)
        {
            count[s[r]]++;
            mfreq = max(mfreq, count[s[r]]);

            while ((r - l + 1) - mfreq > k)
            {
                count[s[l]]--;
                l++;
            }
            res = max(res, (r - l + 1));
        }
        return res;
    }
};
