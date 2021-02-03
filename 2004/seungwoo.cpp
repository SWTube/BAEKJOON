#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long m;
	long long n;
	std::cin >> m >> n;
	
	long long two = 0;
	long long five = 0;

	for (long long i = 2; i <= m; i *= 2) {
		two += m / i;
	}
	for (long long i = 2; i <= n; i *= 2) {
		two -= n / i;
	}
	for (long long i = 2; i <= m - n; i *= 2) {
		two -= (m - n) / i;
	}

	for (long long i = 5; i <= m; i *= 5) {
		five += m / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five -= n / i;
	}
	for (long long i = 5; i <= m - n; i *= 5) {
		five -= (m - n) / i;
	}

	std::cout << std::min(two, five) << "\n";

	return 0;
}