class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> st;

        int n = temperatures.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().second < temperatures[i])
            {
                pair<int, int> top = st.top();
                st.pop();
                res[top.first] = i - top.first;
            }
            st.push({i, temperatures[i]});
        }
        return res;
    }
};
