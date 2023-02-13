#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> primes;
    primes.push_back(2);
    int i = 3;
    while (primes.size() < n)
    {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); j++)
        {
            if (i % primes[j] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            primes.push_back(i);
        }
        i++;
    }
    cout << n << " so nguyen to dau tien la : ";
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
    return 0;
}

