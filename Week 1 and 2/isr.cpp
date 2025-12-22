#include <iostream>
using namespace std;

int interpolation_search_recursive(int A[], int l, int r, int k)
{
    if (l > r)
        return -1;
    int x = l + ((k - A[l]) * (r - l) / (A[r] - A[l]));
    if (A[x] == k)
        return x;
    if (A[x] < k)
        return interpolation_search_recursive(A, x + 1, r, k);
    else
        return interpolation_search_recursive(A, l, x - 1, k);
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {5, 15, -30, 10, -5, 40, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 40;
    bubblesort(A, n);
    int isr = interpolation_search_recursive(A, 0, n - 1, k);
    cout << isr;
    return 0;
}
