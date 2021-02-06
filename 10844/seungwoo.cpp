#include <iostream>
#include <algorithm>

int dp[101][10] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i]++;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}

	int ans = 0;
	
	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[N][i]) % 1000000000;
	}

	std::cout << ans << "\n";

	return 0;
}