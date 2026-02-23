#include <iostream>
using namespace std;

int singlearray(int arr[], int n) {
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (mid % 2 == 1)
			mid--;
		if (arr[mid] == arr[mid + 1])
			l = mid + 2;
		else 
			r = mid;
	}
	return arr[l];
}

int main() {
//	int arr[] = {1, 1, 2, 3, 3, 4, 4, 8, 8}; answer is 2
	int arr[] = {3, 3, 7, 7, 10, 11, 11}; // answer is 10
	int n = sizeof(arr)/sizeof(arr[0]);
	int result = singlearray(arr, n);
	cout << result;
	return 0;
}







