#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortArr(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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
    int n;
    cin >> n;

    int A[100], B[100];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    int intersec[100], uni[200];
    int isz = 0, usz = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                intersec[isz++] = A[i];
                break;
            }
        }
        uni[usz++] = A[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < usz; j++)
        {
            if (B[i] == uni[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            uni[usz++] = B[i];
        }
    }
    
    sortArr(intersec, isz);
    sortArr(uni, usz);

    printArr(intersec, isz);
    printArr(uni, usz);

    return 0;
}

