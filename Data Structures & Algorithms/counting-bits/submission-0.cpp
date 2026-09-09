class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int num = i;
            int count = 0;
            while (num)
            {
                num &= (num - 1);
                count++;
            }
            res[i] = count;
        }
        return res;
    }
};
