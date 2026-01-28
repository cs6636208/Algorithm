#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int r = lower_bound(a.begin(), a.end(), m) - a.begin();
    int l = r - 1;

    vector<int> result;

    while (k > 0)
    {
        if (l < 0)
        {
            result.push_back(a[r]);
            r++;
        }
        else if (r >= n)
        {
            result.push_back(a[l]);
            l--;
        }
        else
        {
            int leftDiff = abs(a[l] - m);
            int rightDiff = abs(a[r] - m);

            if (leftDiff <= rightDiff)
            {
                result.push_back(a[l]);
                l--;
            }
            else
            {
                result.push_back(a[r]);
                r++;
            }
        }
        k--;
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < (int)result.size())
            cout << " ";
    }
    cout << "\n";

    return 0;
}
