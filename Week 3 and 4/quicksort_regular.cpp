#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r + 1;

    while (true)
    {
        do {
            i++;
        } while (i <= r && arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

