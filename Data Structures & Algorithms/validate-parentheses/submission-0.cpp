class Solution {
public:
    bool isValid(string s) {
        
        stack<char> open;

        unordered_map<char, char> parens = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(const auto &ch : s) {
            // if char is in the map
            // check if its a closed parens
            if(parens.find(ch) != parens.end()) {
                // if stack is empty, return false
                if(open.empty()) {
                    return false;
                } 
                // if top of stack isnt what map says, false
                if(open.top() != parens[ch]) {
                    return false;
                }

                // pop top element off stack
                open.pop();

            } else {
                // if char isnt in the map aka if not a closed paren, add it to stack
                // add all open parens to stack
                open.push(ch);
            }
        }

        return open.empty();

    }
};
