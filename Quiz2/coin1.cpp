#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int coin_change(int W, int D[], int n)
{
    int cnts = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (D[i] < D[j])
            {
                int temp = D[i];
                D[i] = D[j];
                D[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (W >= D[i])
        {
            cnts += W / D[i];
            W = W % D[i];
        }
    }

    return cnts;
}

int main()
{
    int n;
    cin >> n;
    int D[n];
    for (int i = 0; i < n; i++)
    {
        cin >> D[i];
    }
    int W;
    cin >> W;
    cout << coin_change(W, D, n) << endl;
    return 0;
}