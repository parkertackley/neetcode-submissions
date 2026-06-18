class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); ++i)
        {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());

        vector<double> fleets;
        for (const auto &car : cars)
        {
            double time = ((double)(target - car.first) / car.second);
            fleets.push_back(time);
            if (fleets.size() >= 2 && fleets[fleets.size() - 2] >= fleets.back())
            {
                fleets.pop_back();
            }
        }
        return fleets.size();    
    }
};
