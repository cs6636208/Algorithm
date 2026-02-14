#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
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
    int A[n], B[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    int unionArr[2 * n], intersectArr[n];
    int unionSize = 0, intersectSize = 0;
    for (int i = 0; i < n; i++)
    {
        unionArr[unionSize++] = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (B[i] == A[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            unionArr[unionSize++] = B[i];
        }
        else
        {
            intersectArr[intersectSize++] = B[i];
        }
    }
    bubbleSort(unionArr, unionSize);
    bubbleSort(intersectArr, intersectSize);
    for (int i = 0; i < intersectSize; i++)
    {
        cout << intersectArr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < unionSize; i++)
    {
        cout << unionArr[i] << " ";
    }
    cout << endl;
    return 0;
}