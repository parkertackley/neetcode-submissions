class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        std::unordered_map<char, int> count;

        for(int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            count[t[i]]--;
        }
        for(int i = 0; i < count.size(); i++) {
            if(count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
