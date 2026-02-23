#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int pass = 0; pass < n - 1; pass++) {
            for (int j = 0; j < n - 1 - pass; j++) {

                if (i % 2 == 0 && a[i][j] > a[i][j + 1]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = temp;
                }

                if (i % 2 == 1 && a[i][j] < a[i][j + 1]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][j + 1];
                    a[i][j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << a[m / 2][n / 2];

    return 0;
}

