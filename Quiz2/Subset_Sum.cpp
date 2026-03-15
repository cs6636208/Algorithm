#include <iostream>
using namespace std;

bool Sum(int A[], int n, int k)
{
    bool S[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        S[i][0] = true;
    }

    for (int j = 1; j <= k; j++)
    {
        S[0][j] = false;
    }

    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j < A[i])
                S[i][j] = S[i - 1][j];
            else
                S[i][j] = S[i - 1][j - 1] || S[i - 1][j - A[i]];
        }
    }
    return S[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int A[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    cout << Sum(A, n, k) << endl;
    return 0;
}