#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex)
    {
        return arr[k];
    }
    else if (k < pivotIndex)
    {
        return quickselect(arr, low, pivotIndex - 1, k);
    }
    else
    {
        return quickselect(arr, pivotIndex + 1, high, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = quickselect(arr, 0, n - 1, k - 1);
    cout << result << endl;
    return 0;
}