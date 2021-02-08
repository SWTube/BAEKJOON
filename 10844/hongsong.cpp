#include <iostream>
#include <cmath>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, dp[101][10], sum = 0;
	std::cin >> n;
	dp[0][0] = 0;
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = (dp[i - 1][j + 1] % 1000000000);
			}
			else if (j == 9)
				dp[i][j] = (dp[i - 1][j - 1] % 1000000000);
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n-1][i]) % 1000000000;
	std::cout << sum;
	return 0;
}