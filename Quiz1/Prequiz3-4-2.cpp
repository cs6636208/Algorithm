#include <iostream>
using namespace std;

int main() {
    int n, column;
    cin >> n >> column;
    
    int Prime[50];
    int NotPrime[50];
    int PrimeCount = 0;
    int NotPrimeCount = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool isPrime = true;
        
        if (num < 1) {
            isPrime = false;
        } else if (num > 1) {
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        
        if (isPrime) {
            Prime[PrimeCount] = num;
            PrimeCount++;
        } else {
            NotPrime[NotPrimeCount] = num;
            NotPrimeCount++;
        }
    }
    
    for (int i = 0; i < PrimeCount - 1; i++) {
        for (int j = 0; j < PrimeCount - i - 1; j++) {
            if (Prime[j] > Prime[j + 1]) {
                int temp = Prime[j];
                Prime[j] = Prime[j + 1];
                Prime[j + 1] = temp;
            }
        }
    }
    
    int result[50];
    int resultCount = 0;
    
    for (int i = 0; i < PrimeCount; i++) {
        result[resultCount] = Prime[i];
        resultCount++;
    }
    for (int i = 0; i < NotPrimeCount; i++) {
        result[resultCount] = NotPrime[i];
        resultCount++;
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i];
        
        if ((i + 1) % column == 0 || i == n - 1) {
            cout << endl;
        } else {
            cout << " "; 
        }
    }
    
    return 0;
}
