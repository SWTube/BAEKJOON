#include <iostream>

int dp[11] = { 0, };

int main() {
	int T; std::cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int test = 0; test < T; test++) {
		int n; std::cin >> n;

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		std::cout << dp[n] << "\n";
	}

	return 0;
}