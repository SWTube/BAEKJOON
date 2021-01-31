#include <iostream>

int dp[31] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	// N = 0; 1
	// N = 2; 3
	// N = 4; 11
	// N = 6; 41
	// ... 
	dp[0] = 1;
	dp[2] = 3;
	
	for (int i = 4; i <= N; i+=2) {
		dp[i] = dp[i - 2] * 3;

		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	
	std::cout << dp[N] << "\n";

	return 0;
}