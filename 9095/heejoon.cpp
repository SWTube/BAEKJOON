#include <iostream>

using namespace std;

int dp[12] = { 0, };

int main() {
	int T;
	int num;
	int sum = 0;
	cin >> T;

	// dp[N] = dp[N-1] + ... + dp[1] + (N-1);
	dp[0] = 0;
	dp[1] = 1; 
	dp[2] = 2; 
	dp[3] = 4;

	for (int i = 0; i < T; i++) {
		cin >> num;

		for (int j = 4; j <= num; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[num] << endl;
	}
}
