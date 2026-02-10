#include <iostream>
using namespace std;

int n;           
int K;             
int V[100];        
int W[100];        
int max_v = -1;   
int ans[100];       

void print_sol(int x[], int r) {
    int w_temp = 0;
    int v_temp = 0;

    for (int i = 1; i <= r; i++) {
        if (x[i] == 1) {
            w_temp += W[i];
            v_temp += V[i];
        }
    }

    if (w_temp <= K && v_temp > max_v) {
        max_v = v_temp;
        for (int i = 1; i <= r; i++)
            ans[i] = x[i];
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
    int x[100];
    cin >> n;
    cin >> K;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
        x[i] = 0;
        
    }
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
        x[i] = 0;
    }
    subset1(x, 0, n);
    cout << max_v << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}


