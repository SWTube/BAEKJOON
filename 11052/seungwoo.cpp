#include <iostream>
#include <algorithm>

int price[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cout.tie(NULL);

	int N; std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> price[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = std::max(dp[i], dp[i - j] + price[j]);
		}
	}
	std::cout << dp[N] << "\n";

	return 0;
}