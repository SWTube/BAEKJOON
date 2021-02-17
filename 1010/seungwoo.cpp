#include <iostream>

int dp[31][31] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		int M;
		std::cin >> N >> M;

		for (int j = 1; j <= M; j++) {
			dp[1][j] = j;
		}

		// <j, k> -> <j, k-1> + <j-1, k-1>
		for (int j = 2; j <= N; j++) {
			for (int k = 2; k <= M; k++) {
				dp[j][k] = dp[j][k - 1] + dp[j - 1][k - 1];
			}
		}

		std::cout << dp[N][M] << "\n";
	}

	return 0;
}