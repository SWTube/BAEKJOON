#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];
int cal[100001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	cal[1] = arr[1];

	for (int i = 2; i <= n; ++i) {
		if (cal[i - 1] + arr[i] >= 0) {
			cal[i] += cal[i - 1] + arr[i];
			dp[i] = max(dp[i - 1], cal[i]);
		}
		else if (cal[i - 1] + arr[i] < 0) {
			cal[i] = 0;
			dp[i] = dp[i - 1];
		}
		if (dp[i] < cal[i]) {
			dp[i] = max(dp[i - 1] ,arr[i]);
		}
	}
	cout << dp[n];
	return 0;
}