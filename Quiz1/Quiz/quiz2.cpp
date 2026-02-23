#include <iostream>
using namespace std;

int a[100];
int bestSum, bestL, bestR;

void maxSub(int L, int R, int k) {
    if (L > R) return;

    if (L == R) {
        if (a[L] > bestSum) {
            bestSum = a[L];
            bestL = bestR = L;
        }
        return;
    }

    int mid = (L + R) / 2;

    maxSub(L, mid, k);
    maxSub(mid + 1, R, k);

    for (int i = L; i <= R; i++) {
        int sum = 0;
        for (int j = i; j <= R && j - i + 1 <= k; j++) {
            sum += a[j];
            if (sum > bestSum) {
                bestSum = sum;
                bestL = i;
                bestR = j;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    int mid = (n - 1) / 2;

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        bestSum = -1000000;
        
        if (i == 0)
            maxSub(0, mid, k);
        else
            maxSub(mid + 1, n - 1, k);

        cout << k << " ";
        for (int j = bestL; j <= bestR; j++)
            cout << a[j] << " ";
        cout << endl;
    }

    return 0;
}

