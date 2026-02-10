#include <iostream>
#include <cmath>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool isSolution(int X[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(X[i] - X[j]) == abs(i - j))
                return false;
        }
    }
    return true;
}

void permute(int X[], int start, int end, int n, int &count) {
    if (start == end) {
        if (isSolution(X, n)) {
            count++;
            for (int i = 1; i <= n; i++)
                cout << X[i] << " ";
            cout << endl;
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(X[start], X[i]);
        permute(X, start + 1, end, n, count);
        swap(X[start], X[i]); 
    }
}

int main() {
    int n;
    cin >> n;

    int X[n + 1];
    for (int i = 1; i <= n; i++)
        X[i] = i;   

    int count = 0;
    permute(X, 1, n, n, count);
    
    cout << count << endl;
    return 0;
}





