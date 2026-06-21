class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);  
    }
    
    string get(string key, int timestamp) {
        auto& entry = mp[key];
        int l = 0, r = entry.size() - 1;
        string res = "";

        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (entry[mid].first > timestamp)
            {
                r = mid - 1;
            } else if (entry[mid].first <= timestamp)
            {
                res = entry[mid].second;
                l = mid + 1;
            }
        }
        return res;
    }
};
