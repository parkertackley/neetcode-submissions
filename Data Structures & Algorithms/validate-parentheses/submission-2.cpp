class Solution {
public:
    bool isValid(string s) {
        
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        stack<char> st;
        for (const char c : s)
        {
            if (mp.contains(c))
            {
                if (st.empty())
                    return false;
                
                if (st.top() != mp[c])
                    return false;

                st.pop();

            } else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};
