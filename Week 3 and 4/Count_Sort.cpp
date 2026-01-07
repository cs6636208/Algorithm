#include <iostream>
using namespace std;

void count_Sort(int A[], int n) {
	int max = A[0];
	for (int i = 0; i < n; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	int count[max + 1];
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[A[i]]++;
	}
	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			A[index++] = i;
			count[i]--;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	count_Sort(A, n);
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	return 0;
}
