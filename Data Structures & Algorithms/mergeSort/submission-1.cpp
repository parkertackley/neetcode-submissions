// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        merge(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void merge(vector<Pair>& pairs, int s, int e) {
        if(e - s + 1 <= 1) {
            return;
        }

        int m = (s + e) / 2;

        merge(pairs, s, m);

        merge(pairs, m + 1, e);

        mergeArr(pairs, s, m, e);

    }

    void mergeArr(vector<Pair>& arr, int s, int mid, int e) {
        vector<Pair> leftArray = {arr.begin() + s, arr.begin() + mid + 1};
        vector<Pair> rightArray = {arr.begin() + mid + 1, arr.begin() + e + 1};

        int l = 0;
        int r = 0;
        int m = s;

        while(l < leftArray.size() && r < rightArray.size()) {
            if(leftArray[l].key <= rightArray[r].key) {
                arr[m] = leftArray[l];
                l++;
            } else {
                arr[m] = rightArray[r];
                r++;
            }
            m++;
        }

        while(l < leftArray.size()) {
            arr[m] = leftArray[l];
            m++;
            l++;
        }

        while(r < rightArray.size()) {
            arr[m] = rightArray[r];
            m++;
            r++;
        }

    }

};
