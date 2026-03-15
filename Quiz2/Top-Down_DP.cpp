#include <iostream>
using namespace std;

int dp[100][100];

int C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = C(n - 1, k - 1) + C(n - 1, k);

    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << C(n, k) << endl;
    return 0;
}