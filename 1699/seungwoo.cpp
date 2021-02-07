#include <iostream>
#include <algorithm>

int dp[100001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i;

		for (int j = 1; j * j <= i; j++) {
			dp[i] = std::min(dp[i], dp[i - j * j] + 1);
		}
	}

	std::cout << dp[N] << "\n";

	return 0;
}