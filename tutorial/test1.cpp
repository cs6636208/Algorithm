#include <iostream>
using namespace std;

int power(int x, int n)
{
	int product = 1;
	for (int i = 0; i < n; i++)
	{
		product = product * x;
	}
	return product;
}

void mystery(int x, int n)
{
	int S = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			S = S + 1;
		}
	}
	cout << S << endl;
}

int sum(int n)
{
	int S = 0;
	int i = 1;
	while (i <= n)
	{
		S = S + 1;
		i = i + 1;
	}
	return S;
}

int main()
{
	//    int n;
	//    cin >> n;
	//    int arr[n];
	//    int i = 0;
	//    while (i < n) {
	//        cin >> arr[i];
	//        if (arr[i] == 0) {
	//            cout << arr[i];
	//            break;
	//        }
	//        i++;
	//    }
	int x, n;
	cin >> x >> n;
	int Power = power(x, n);
	cout << Power << endl;
	mystery(x, n);
	int sumn = sum(n);
	cout << sumn << endl;
	return 0;
}
