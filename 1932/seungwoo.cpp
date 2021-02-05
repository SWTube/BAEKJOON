#include <iostream>
#include <algorithm>

int dp[501][501] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n; std::cin >> n;
	int maxScore = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> dp[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[i][j] += dp[i - 1][j];
			}
			else if (j == n) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] += std::max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		maxScore = std::max(maxScore, dp[n][i]);
	}

	std::cout << maxScore << "\n";

	return 0;
}