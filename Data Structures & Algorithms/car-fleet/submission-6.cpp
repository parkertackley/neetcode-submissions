class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        vector<double> st;
        for (auto& car : cars)
        {
            double time = (double)(target - car.first) / car.second;
            st.push_back(time);
            if (st.size() > 1 && st[st.size() - 2] >= st.back())
            {
                st.pop_back();
            } 
        }
        return st.size();
    }
};
