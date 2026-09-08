class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(const string& s : strs) {

            vector<int> count(26, 0);
            for(const char& c : s) {
                count[c - 'a']++;
            }

            string res = to_string(count[0]);
            for(int i = 1; i < 26; i++) {
                res += ',' + to_string(count[i]);
            }
            mp[res].push_back(s);
        }

        vector<vector<string>> result;
        for(const auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;

    }
};
