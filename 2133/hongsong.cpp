#include <iostream>
using namespace std;

int main() {
	int n, dp[33];
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	//dp[4] = dp[2]*dp[2] + 1*2
	//dp[6] = dp[4]*dp[2] + 2*dp[2] + 1*2 = 41
	//dp[8] = dp[6]*dp[2] + 2*dp[4] + 2*dp[2] + 1*2 = 153
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = (dp[i - 2] * dp[2]) + 2;
			for (int j = i-4; j >= 2; j -= 2)
				dp[i] += 2 * dp[j];
		}
		else
			dp[i] = 0;
	}
	cout << dp[n];

	return 0;
}