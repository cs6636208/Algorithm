#include <iostream>
using namespace std;

int sumarray(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int avgarray(int arr[], int n)
{
	int sumarr = sumarray(arr, n);
	double avg = 0.0;
	avg = sumarr / n;
	return avg;
}

void reversearray(int arr[], int n)
{
	int temp[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[n - i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}

void bubblesort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	cout << "Please Input Number : ";
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else
			min = arr[i];
	}
	cout << "Max Array : " << max << endl;
	cout << "Min Array : " << min << endl;
	int Sumarray = sumarray(arr, n);
	cout << "Sum Array : " << Sumarray << endl;
	int Avgarray = avgarray(arr, n);
	cout << "Avg Array : " << Avgarray << endl;
	cout << "Reverse Array : " << endl;
	reversearray(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Sort Array : " << endl;
	bubblesort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
