class Solution {
public:

    string encode(vector<string>& strs) {

        string res = "";

        for(const string& s : strs) {
            int length = s.size();
            res += to_string(length) + '#' + s;
        }

        return res;

    }

    vector<string> decode(string s) {

        vector<string> res;

        int i = 0;
        while(i < s.size()) {

            int j = i;
            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            cout << length;
            string word = s.substr(j + 1, length);
            res.push_back(word);
            i = j + 1 + length;

        }

        return res;

    }
};
