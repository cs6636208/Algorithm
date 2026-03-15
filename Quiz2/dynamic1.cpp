#include <bits/stdc++.h>
using namespace std;
int memo[6] = {-1, -1, -1, -1, -1, -1};

int f_t(int n)
{
    if (n < 2)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = f_t(n - 1) + f_t(n - 2);
    return memo[n];
}

int main()
{
    cout << f_t(5) << endl;
    return 0;
}
