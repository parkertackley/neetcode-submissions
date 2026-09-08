class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int> store;

        for(int i = 0; i < nums.size(); i++) {
            if(find(store.begin(), store.end(), nums[i]) != store.end()) {
                return true;
            } else {
                store.push_back(nums[i]);
            }
        }

        return false;

    }
};
