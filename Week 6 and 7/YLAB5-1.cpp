#include <iostream>
using namespace std;

int p[20];
bool used[21];
int N;
int totalCount = 0;

void findPermutations(int index) {
    if (index == N) {
        for (int i = 0; i < N; i++) {
            cout << p[i] << (i < N - 1 ? " " : "");
        }
        cout << endl;
        totalCount++;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            used[i] = true;
            p[index] = i;
            findPermutations(index + 1);
            used[i] = false;
        }
    }
}

int main() {
    if (cin >> N) {
        findPermutations(0);
        cout << totalCount << endl;
    }
    return 0;
}
