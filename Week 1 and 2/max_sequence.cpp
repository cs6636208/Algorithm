#include <iostream>
using namespace std;

void max_sequence(int arr[], int n)
{
	int sum, max = -1000;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = 0;
			for (int k = i; k <= j; k++)
			{
				sum += arr[k];
				if (sum > max)
					max = sum;
			}
		}
	}
	cout << max;
}

int main()
{
	int arr[] = {5, 15, -30, 10, -5, 40, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	max_sequence(arr, n);
	return 0;
}
