#include <iostream>
#include <vector>
using namespace std;

void medianOfThree(vector<int> &arr, int l, int r) {
    int mid = (l + r) / 2;

    if (arr[l] > arr[mid]) swap(arr[l], arr[mid]);
    if (arr[l] > arr[r])   swap(arr[l], arr[r]);
    if (arr[mid] > arr[r]) swap(arr[mid], arr[r]);

    swap(arr[mid], arr[r]);
}

int partition(vector<int> &arr, int l, int r) {
    medianOfThree(arr, l, r);
    int pivot = arr[r];

    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;   
}

int quickSelect(vector<int> &arr, int low, int high, int k) {
    if (low == high)
        return arr[low];

    int p = partition(arr, low, high);

    if (p == low + k - 1)              
        return arr[p];
    else if (p > low + k - 1)          
        return quickSelect(arr, low, p - 1, k);
    else {                             
        k = k - (p - low + 1);
        return quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << quickSelect(arr, 0, n - 1, k);
    return 0;
}

