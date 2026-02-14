#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prime[50];
    int notprime[50];
    int primecount = 0;
    int notprimecount = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        bool isprime = true;
        if (num < 1)
        {
            isprime = false;
        }
        else if (num > 1)
        {
            for (int j = 2; j * j <= num; j++)
            {
                if (num % j == 0)
                {
                    isprime = false;
                    break;
                }
            }
        }
        if (isprime)
        {
            prime[primecount] = num;
            primecount++;
        }
        else
        {
            notprime[notprimecount] = num;
            notprimecount++;
        }
    }

    for (int i = 0; i < primecount - 1; i++)
    {
        for (int j = 0; j < primecount - i - 1; j++)
        {
            if (prime[j] > prime[j + 1])
            {
                int temp = prime[j];
                prime[j] = prime[j + 1];
                prime[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < primecount; i++)
    {
        cout << prime[i] << " ";
    }
    for (int i = 0; i < notprimecount; i++)
    {
        cout << notprime[i] << " ";
    }
    return 0;
}