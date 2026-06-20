class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }        
        sort(cars.rbegin(), cars.rend());

        vector<double> fleet;
        for (const auto &car : cars)
        {
            double time = ((double)(target - car.first) / car.second);
            fleet.push_back(time);
            if (fleet.size() > 1 && time <= fleet[fleet.size() - 2])
            {
                fleet.pop_back();
            }
        }
        return fleet.size();
    }
};
