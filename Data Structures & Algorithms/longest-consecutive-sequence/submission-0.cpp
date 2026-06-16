class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> ns(nums.begin(), nums.end());
        int res = 0;

        int n = ns.size();
        for (int i : ns)
        {
            if (!ns.contains(i - 1))
            {
                int length = 1;
                while (ns.contains(i + length))
                {
                    length++;
                }

                res = max(length, res);
            }
        }
        return res;
    }
};
