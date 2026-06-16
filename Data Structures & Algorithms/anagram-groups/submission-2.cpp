class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for (string s : strs)
        {
            vector<int> count(26, 0);

            for (int i = 0; i < s.size(); i++)
            {
                count[s[i] - 'a']++;
            }

            string key = to_string(count[0]);
            for (int i = 0; i < 26; i++)
            {
                key += "," + to_string(count[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (const auto entry : mp)
        {
            res.push_back(entry.second);
        }

        return res;
    }
};
