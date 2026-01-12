#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int Partition(vector<int>& A, int l, int r) {
    int p = A[l]; 
    int i = l;
    int j = r + 1; 

    do {
        do {
            i++;
        } while (i <= r && A[i] < p); 

        do {
            j--;
        } while (A[j] > p);

        std::swap(A[i], A[j]);

    } while (i < j); 

    std::swap(A[i], A[j]);

    std::swap(A[l], A[j]);

    return j; 
}

void Quicksort(vector<int>& A, int l, int r) {
    if (l < r) {
        int s = Partition(A, l, r); 
        cout << "Pivot placed at index " << s << ": ";
        printArray(A);
        Quicksort(A, l, s - 1); 
        Quicksort(A, s + 1, r); 
    }
}

int main() {
    vector<int> arr = {16, 25, 2, 54, 36, 9, 12, 66};
    int n = arr.size();

    cout << "Original Array: ";
    printArray(arr);
    
    Quicksort(arr, 0, n - 1);
    cout << "Sorted Array:   ";
    printArray(arr);
    
    return 0;
}
