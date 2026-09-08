class Solution {
public:
    bool isPalindrome(string s) {
        int ss = s.size();
        if(ss == 1 || ss == 0)
            return true;

        int l = 0;
        int r = s.size() - 1;

        while(l < r) {
            if(!isalnum(s[r])) {
                --r;
            } else if(!isalnum(s[l])) {
                ++l;
            } else if(tolower(s[l]) != tolower(s[r])) {
                return false;
            } else {
                ++l;
                --r;
            }
        }

        return true;

    }
};
