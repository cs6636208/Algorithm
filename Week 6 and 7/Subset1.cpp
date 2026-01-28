#include <iostream>
using namespace std;

void printsol(int X[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void subset1(int X[], int l, int r)
{
    if (l == r)
    {
        printsol(X, r);
    }
    else
    {
        X[l + 1] = 1;
        subset1(X, l + 1, r);
        X[l + 1] = 0;
        subset1(X, l + 1, r);
    }
}

int main()
{
    int n = 3;
    int X[n + 1];
    subset1(X, 0, n);
    return 0;
}