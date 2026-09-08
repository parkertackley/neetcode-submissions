class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        vector<int> count(3, 0);

        for(const int& i : nums) {
            count[i]++;
        }

        int i = 0;
        for(int n = 0; n < 3; n++) {
            for(int j = 0; j < count[n]; j++) {
                nums[i] = n;
                i++;
            }
        }
        return;
    }
};