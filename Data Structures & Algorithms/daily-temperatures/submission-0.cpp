class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> days;

        for(int i = 0; i < temperatures.size(); ++i) {

            while(!days.empty() && temperatures[i] > days.top().first) {
                auto temp = days.top();
                days.pop();
                res[temp.second] = i - temp.second;
            }

            days.push({temperatures[i], i});

        }

        return res;

    }
};