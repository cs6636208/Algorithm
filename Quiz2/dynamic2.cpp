#include <iostream>
using namespace std;

int memo[6] = {-1, -1, -1, -1, -1, -1};

int f(int n)
{
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

int main()
{
    cout << f(5) << endl;
    return 0;
}