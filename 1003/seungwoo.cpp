#include <iostream>

int dp[41][2] = { 0, };

int main() {
	int T; std::cin >> T;

	dp[0][0] = 1;
	dp[1][1] = 1;

	for (int test = 0; test < T; test++) {
		int N; std::cin >> N;

		for (int i = 2; i <= N; i++) {
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
		}
		
		std::cout << dp[N][0] << ' ' << dp[N][1] << "\n";
	}

	return 0;
}