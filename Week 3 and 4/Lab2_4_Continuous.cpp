#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    sort(A, A + n);
    int max_len = 1;     
    int current_len = 1;  

   
    for (int i = 1; i < n; i++) {
       
        if (A[i] == A[i-1] + 1) {
            current_len++; 
        } else {
            
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 1;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
    }
    cout << max_len << endl;
    return 0;
}
