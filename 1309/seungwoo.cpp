#include <iostream>

int dp[100001];

// N = 1: 3
// N = 2: 7
// N = 3: 17
// N = 4: 41

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= N; i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}

	std::cout << dp[N] << "\n";

	return 0;
}