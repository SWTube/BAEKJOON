#include <iostream>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long n; std::cin >> n;
	long long ans = sqrt(n);

	if (pow(ans, 2) >= n) {
		std::cout << ans << "\n";
	}
	else {
		std::cout << ans + 1 << "\n";
	}

	return 0;
}