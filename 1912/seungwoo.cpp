#include <iostream>
#include <algorithm>

int series[100001] = { 0, };
int dp[100001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n; std::cin >> n;
	int maxNum = 0;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> series[i];
	}

	dp[1] = series[1];
	maxNum = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = std::max(series[i], dp[i - 1] + series[i]);
		maxNum = std::max(maxNum, dp[i]);
	}

	std::cout << maxNum << "\n";

	return 0;
}