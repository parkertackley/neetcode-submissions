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
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortHelper(vector<Pair>& arr, int s, int e) {

        // once we reach a single element array we return
        // BASE CASE
        if(e - s + 1 <= 1)
            return;

        // save the pivot element
        Pair pivot = arr[e];
        // left pointer
        int l = s;

        // since were working with arrays that will be smaller than the actual array,
        // we need to loop through starting at the "s" index up until right before the ending/pivot (in our case) index
        for(int i = s; i < e; i++) {
            if(arr[i].key < pivot.key) {
                swap(arr[i], arr[l]);
                l++;
            }
        }

        arr[e] = arr[l];
        arr[l] = pivot;

        quickSortHelper(arr, s, l - 1);

        quickSortHelper(arr, l + 1, e);

    }
};
