#include <iostream>
using namespace std;

int binary_search_recursive(int A[], int l, int r, int k)
{
	if (l > r)
		return -1;
	int mid = (l + r) / 2;
	if (A[mid] == k)
		return mid;
	if (A[mid] < k)
		return binary_search_recursive(A, mid + 1, r, k);
	else
		return binary_search_recursive(A, l, mid - 1, k);
}

int main()
{
	int A[] = {5, 15, -30, 10, -5, 40, 10};
	int n = sizeof(A) / sizeof(A[0]);
	int k = 40;
	int bsr = binary_search_recursive(A, 0, n - 1, k);
	cout << bsr;
	return 0;
}
