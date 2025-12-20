#include <iostream>
using namespace std;

int arrSum(int arr[], int n) {
	if (n == 0)
		return 0;
		
	return arr[n - 1] + arrSum(arr, n - 1);
} 

int main() {
	int n;
	cout << "Input: ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = arrSum(arr, n);
	cout << "Output: " << sum << endl;
	return 0;
}





