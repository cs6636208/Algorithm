#include <iostream>
using namespace std;

int max(int A[], int n)
{
	if (n == 0)
		return A[0];
	int y = max(A, n - 1);
	return y > A[n] ? y : A[n];
}

int main()
{
	int n;
	cout << "Input: ";
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int result = max(A, n - 1);
	cout << "Output: " << result;
	return 0;
}
