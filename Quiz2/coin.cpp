#include <iostream>
#include <algorithm>
using namespace std;

int best = 1000000000;
int best_used[100];

void backtrack(int i, int W, int n, int D[], int C[], int used[], int cnt)
{
    if (W == 0)
    {
        if (cnt < best)
        {
            best = cnt;
            for (int k = 0; k < n; k++)
                best_used[k] = used[k];
        }
        return;
    }
    if (i == n || cnt >= best)
        return;
    for (int k = min(C[i], W / D[i]); k >= 0; k--)
    {
        used[i] = k;
        backtrack(i + 1, W - k * D[i], n, D, C, used, cnt + k);
    }
    used[i] = 0;
}

int main()
{
    int n;
    cin >> n;
    int D[n], C[n];
    for (int i = 0; i < n; i++)
        cin >> D[i];

    for (int i = 0; i < n; i++)
        cin >> C[i];
    int W;
    cin >> W;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (D[i] < D[j])
            {
                swap(D[i], D[j]);
                swap(C[i], C[j]);
            }
        }
    }
    int used[n] = {0};
    backtrack(0, W, n, D, C, used, 0);
    if (best == 1000000000)
    {
        cout << "impossible";
        return 0;
    }

    cout << best << endl;
    for (int i = 0; i < n; i++)
    {
        if (best_used[i] > 0)
            cout << D[i] << ":" << best_used[i] << endl;
    }
    return 0;
}
