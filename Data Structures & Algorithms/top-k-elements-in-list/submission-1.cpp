class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> count;
        for (const int i : nums)
        {
            count[i]++;
        }
        
        vector<vector<int>> freq(nums.size() + 1);
        for (const auto entry : count)
        {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (const int i : freq[i])
            {
                res.push_back(i);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
