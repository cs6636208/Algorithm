#include <iostream>
using namespace std;

void twosum(int arr[], int n, int x)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == x)
			{
				cout << arr[i] << ", " << arr[j] << endl;
			}
		}
	}
}

int main()
{
	int arr[] = {5, 15, -30, 10, -5, 40, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 20;
	twosum(arr, n, x);
	return 0;
}
