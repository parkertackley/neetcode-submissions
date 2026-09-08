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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quick(pairs, 0, pairs.size() - 1);
        return pairs;
    }

private:
    void quick(vector<Pair>& arr, int s, int e) {
        if(e - s + 1 <= 1)
            return;

        Pair pivot = arr[e];
        int left = s;

        for(int i = s; i < e; i++) {
            if(arr[i].key < pivot.key) {
                swap(arr[left], arr[i]);
                left++;
            }
        }

        arr[e] = arr[left];
        arr[left] = pivot;

        quick(arr, s, left - 1);
        quick(arr, left + 1, e);

    }

};
