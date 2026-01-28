#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int X[], int start, int end)
{
    if (start == end)
    {
        for (int i = 1; i <= end; i++)
        {
            cout << X[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(&X[start], &X[i]);
        permute(X, start + 1, end);
        swap(&X[start], &X[i]); // backtrack
    }
}

int main()
{
    int n = 3;
    int X[] = {-1, 1, 2, 3};
    permute(X, 1, n);
    return 0;
}