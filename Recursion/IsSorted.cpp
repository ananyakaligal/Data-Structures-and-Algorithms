#include <iostream>
using namespace std;

bool isSorted(int *arr, int size) {
    if (size == 0 || size == 1) return true;

    if (arr[0] > arr[1]) return false;
    
    else {
        bool remaining = isSorted(arr + 1, size - 1);
        return remaining;
    }
}

int main() {
    int arr[5] = {2, 3, 5, 6, 7};
    int size = 5;
    
    bool ans = isSorted(arr, size);
    
    if (ans) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
