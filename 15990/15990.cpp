#include <iostream>
#include <vector>

using namespace std;


int main() {
	int Input;
	cin >> Input;

	for (int k = 0; k < Input; k++) {
		int n;
		cin >> n;

		vector<vector<long long int>> dp(n + 1, vector<long long int>(4, 0));

		dp[1][1] = 1;
		dp[2][2] = 1;
		dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

		for (int i = 4; i <= 100000; i++) {
			dp[i][1] = dp[i - 2][2] + dp[i - 3][3];
			dp[i][2] = dp[i - 1][1] + dp[i - 3][3];
			dp[i][3] = dp[i - 1][1] + dp[i - 2][2];

			dp[i][1] %= 1000000009;
			dp[i][2] %= 1000000009;
			dp[i][3] %= 1000000009;
		}
		cout << (dp[n][1] + dp[n][2] + dp[n][3] - 1) % 1000000009 << endl;
	}
}