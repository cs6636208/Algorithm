#include <iostream>
using namespace std;

int A[100];
int X;

void print_sol(int x[], int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            sum += A[i];
        }
    }

    if (sum == X) {
        for (int i = 1; i <= n; i++) {
            if (x[i] == 1) {
                cout << A[i] << " ";
            }
        }
        cout << endl;
    }
}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
        x[l + 1] = 1;              
        subset1(x, l + 1, r);

        x[l + 1] = 0;            
        subset1(x, l + 1, r);
    }
}

int main() {
    int n;
    int x[100];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    cin >> X;
    subset1(x, 0, n);
    return 0;
}



