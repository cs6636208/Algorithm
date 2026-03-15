#include <iostream>
using namespace std;

int Fun_C(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    if (k < 0 || k > n)
        return 0;
    return Fun_C(n - 1, k - 1) + Fun_C(n - 1, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << Fun_C(n, k) << endl;
    return 0;
}
