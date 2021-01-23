#include <iostream>
#define MIN(x, y) (x < y ? x : y)
int dp[1000001];

using namespace std;
int main(void) {

	int N;
	cin >> N;

	int i;
	for (i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = MIN(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = MIN(dp[i], dp[i / 3] + 1);
	}
	cout << dp[N];
	return 0;

}
// copy-solved!
/*
1. 3으로 나누어 떨어지는 경우 -> dp[n] = dp[n/3] + 1
2. 2로 나누어 떨어지는 경우 -> dp[n] = dp[n/2] + 1
3. 1을 빼는 경우 -> dp[n] = dp[n-1] + 1
*/