#include <bits/stdc++.h>
using namespace std;

vector<int> Search(vector<int> A, int M, int k)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int i = lower_bound(A.begin(), A.end(), M) - A.begin();
    int left = i - 1;
    int right = i;
    while ((right - left - 1) < k)
    {
        cout << "Left: " << left << ", Right: " << right << endl;
        if (left < 0)
        {
            right++;
        }
        else if (right >= n)
        {
            left--;
        }
        else
        {
            if (abs(A[left] - M) > abs(A[right] - M))
            {
                right++;
            }
            else
            {
                left--;
            }
        }
    }
    vector<int> result;
    for (int idx = left + 1; idx < right; idx++)
    {
        result.push_back(A[idx]);
    }
    return result;
}

int main()
{
    vector<int> A = {10, 12, 15, 17, 18, 20, 25};
    int k = 2;
    int M = 8;
    vector<int> nearest = Search(A, M, k);
    for (int num : nearest)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
