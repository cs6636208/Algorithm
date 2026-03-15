// Quiz Algorithm 2: SumCnk
#include <iostream>
using namespace std;

int SumCnk(int n, int k)
{
    if (k > n)
        return 0;
    if (k < 0)
        return 0;

    if (k == 0)
        return n;
    if (k == n)
        return n * n;

    return SumCnk(n - 1, k - 1) + SumCnk(n - 1, k);
}

int main()
{
    int s;
    cin >> s;
    int sum = 0;
    for (int j = 0; j < s; j++)
    {
        sum += SumCnk(s - j, j + 1);
    }
    cout << sum << endl;
    return 0;
}
