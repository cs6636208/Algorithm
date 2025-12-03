#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Input : ";
    cin >> n;
    int sum = 0;
    sum = n * (n + 1) / 2;
    cout << "Output : " << sum << endl;
    return 0;
}