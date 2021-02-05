#include <iostream>
#include <cmath>
using namespace std;

int findFactor(int n, int k) {
	int count = 0;

	for (int i = 1; n / pow(k, i) >= 1; i++) {
		count += n / int(pow(k, i));
	}
	return count;
}

int main() {
	int n, m, five = 0, two = 0;
	cin >> n >> m;
	if (n == m || m == 0)
		cout << "0";
	else {
		five = findFactor(n, 5) - (findFactor(m, 5) + findFactor(n - m, 5));
		two = findFactor(n, 2) - (findFactor(m, 2) + findFactor(n - m, 2));
		if (five == 0 || two == 0)
			cout << "0";
		else
			cout << min(five, two);
	}
	return 0;
}