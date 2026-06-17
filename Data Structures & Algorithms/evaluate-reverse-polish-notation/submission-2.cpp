class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string s : tokens)
        {
            if (s == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            } else if (s == "-")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            } else if (s == "*")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            } else if (s == "/")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            } else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
