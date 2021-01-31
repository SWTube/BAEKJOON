#include <iostream>
#include <algorithm>

int dp[10001] = { 0 };
int wine[10001] = { 0 };

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> wine[i];
	}

	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = std::max(dp[i - 3] + wine[i] + wine[i - 1], dp[i - 2] + wine[i]);
		dp[i] = std::max(dp[i], dp[i - 1]);
	}

	std::cout << dp[n] << "\n";

	return 0;
}