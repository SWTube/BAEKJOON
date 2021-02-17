#include <iostream>
using namespace std;
int dp[12] = { 0, 1, 2, 4 };
int main() {
	for (int i = 4; i <= 10; ++i) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	int T; cin >> T;
	for (int i = 0; i < T; ++i) {
		int N; cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}