#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000001;

int minFactor[MAX];
vector<int> prime;

void eratosthenes()
{
	for (int i = 2; i < MAX; i++)
		minFactor[i] = i;
		
	for (int i = 2; i * i < MAX; i++)
		if (minFactor[i] == i)
			for (int j = i + i; j < MAX; j += i)
				if (minFactor[j] == j)
					minFactor[j] = i;

	for (int i = 3; i < MAX; i++)
		if (minFactor[i] == i)
			prime.push_back(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	eratosthenes();

	int n;
	while (true)
	{
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < prime.size(); i++)
		{
			if (n - prime[i] < 0)
			{
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}
			if (minFactor[n - prime[i]] == n - prime[i])
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
				break;
			}
		}
	}

	return 0;
}