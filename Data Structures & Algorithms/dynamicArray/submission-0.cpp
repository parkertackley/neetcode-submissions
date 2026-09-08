class DynamicArray {
public:

    int size;
    int *arr;
    int cap;

    DynamicArray(int capacity) {
        arr = new int[capacity];
        cap = capacity;
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == cap) {
            resize();
        }

        arr[size++] = n;
    }

    int popback() {
        int n = arr[size - 1];
        arr[size--];

        return n;
    }

    void resize() {
        cap = 2 * cap;
        int* newArr = new int[cap];

        for(int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        arr = newArr;

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
