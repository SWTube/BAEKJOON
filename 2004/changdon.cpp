#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long PrimeFactor(int n, int x)
{
	int num = 0;

	for (long long i = x; n / i >= 1; i *= x)
	{
		num += n / i;
	}

	return num;
}

int main()
{
	int n, m;

	long long five = 0;
	long long two = 0;

	cin >> n;
	cin >> m;

	five = PrimeFactor(n, 5) - PrimeFactor(n - m, 5) - PrimeFactor(m, 5);
	two = PrimeFactor(n, 2) - PrimeFactor(n - m, 2) - PrimeFactor(m, 2);

	cout << min(five, two) << endl;

	return 0;
}