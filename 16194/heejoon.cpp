#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	vector<int> p(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> p[i+1];
	}

	dp[0] = 0;
	for(int i=1;i<=n;i++)
		dp[i] = 1000 * 10000; // default value: maximun of dp[n]

	// dp[N] = min(dp[N],dp[N-i] + p[i])
	for (int N = 1; N <= n; N++) {
		for (int i = 1; i <= N; i++) {
			dp[N] = min(dp[N], dp[N - i] + p[i]);
		}
	}
	cout << dp[n];
}