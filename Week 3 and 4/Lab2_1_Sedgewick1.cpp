#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    if (n == 1) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true; 
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void shellSort(int A[], int n) {
    int gap[1000];
    int gapCount = 0;
    
    for (int i = 1; i <= n; i++) {
        if (prime(i)) {
            gap[gapCount++] = i;
        }
    }

    for (int g = gapCount - 1; g >= 0; g--) {
        int k = gap[g];

        for (int i = k; i < n; i++) {
            int temp = A[i];
            int j = i;

            while (j >= k && A[j - k] > temp) {
                A[j] = A[j - k];
                j -= k;
            }
            A[j] = temp;
        }

        printArray(A, n);
    }
}

int main() {
    int n;
    cin >> n;

    int A[1000];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    shellSort(A, n);
    return 0;
}

