#include <iostream>
#include <string>

using namespace std;

int M, N;
int totalPeople;
int totalCount = 0;

string people[30];
string currentSeat[30];
bool used[30];

void solve(int index) {
    if (index == totalPeople) {
        bool isValid = true;
        for (int i = 0; i < totalPeople - 1; i++) {
            if (currentSeat[i] == "g1" && currentSeat[i+1] == "g2") {
                isValid = false;
                break;
            }
            if (currentSeat[i] == "g2" && currentSeat[i+1] == "g1") {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            for (int i = 0; i < totalPeople; i++) {
                cout << currentSeat[i];
                if (i < totalPeople - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            totalCount++;
        }
        return;
    }

    for (int i = 0; i < totalPeople; i++) {
        if (!used[i]) {
            used[i] = true;
            currentSeat[index] = people[i];
            solve(index + 1);
            used[i] = false;
        }
    }
}

int main() {
    if (cin >> M >> N) {
        totalPeople = M + N;
        int k = 0;

        for (int i = 1; i <= M; i++) {
            people[k] = "b" + to_string(i);
            k++;
        }

        for (int i = 1; i <= N; i++) {
            people[k] = "g" + to_string(i);
            k++;
        }

        for(int i = 0; i < totalPeople; i++) {
            used[i] = false;
        }

        solve(0);
        
        cout << totalCount << endl;
    }
    return 0;
}
