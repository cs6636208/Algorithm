#include <iostream>
using namespace std;

int findmax(int arr[], int i, int j) {
	if (i == j)
		return arr[i];
	int mid = (i + j) / 2;
	int m1 = findmax(arr, i, mid);
	int m2 = findmax(arr, mid+1, j);
	return (m1 > m2) ? m1 : m2;
}

int main() {
	int n;
	cout << "Input: ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = findmax(arr, 0, n - 1);
	cout << "Output: " << max << endl;
	return 0;
}







