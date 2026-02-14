#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void search(int arr[], int n, int k, int m)
{
    bubblesort(arr, n);
    int i = 0;
    while (i < n && arr[i] < m)
    {
        i++;
    }

    int left = i - 1;
    int right = i;
    while (left - right <= k)
    {
        cout << left << " " << right << endl;
        if (left < 0 && right >= n)
            break;
        if (left < 0)
        {
            right = right + 1;
        }
        else if (right >= n)
        {
            left = left - 1;
        }
        else
        {
            if (abs(arr[left] - m) > abs(arr[right] - -m))
            {
                right++;
            }
            else
            {
                left--;
            }
        }
    }
    for (int j = left + 1; j < right; j++)
    {
        if (j >= 0 && j < n)
        {
            cout << arr[j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    search(arr, n, k, m);
    return 0;
}