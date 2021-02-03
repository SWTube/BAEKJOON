#include <iostream>

using namespace std;

int main() {

	unsigned long long n, m;
	cin >> n >> m;

	int fiveNum = 0, twoNum = 0, divFiveNum = 0, divTwoNum = 0;
	int term;

	term = n - m;


	for (long long i = 2; i <= n; i *= 2) {
		twoNum += n / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		divTwoNum += m / i;
	}
	for (long long i = 2; i <= term; i *= 2) {
		divTwoNum += term / i;
	}

	for (long long i = 5; i <= n; i *= 5) {
		fiveNum += n / i;
	}
	for (long long i = 5; i <= m; i *= 5) {
		divFiveNum += m / i;
	}
	for (long long i = 5; i <= term; i *= 5) {
		divFiveNum += term / i;
	}

	fiveNum -= divFiveNum;
	twoNum -= divTwoNum;

	cout << min(fiveNum, twoNum);

	return 0;
}