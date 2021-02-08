#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	
	// dp[i] = min(dp[i], dp[i-j*j] + (dp[j*j]==1) )
	for (int i = 0; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	
	cout << dp[N];
}
/*
* dp[N] = N * dp[1]
* dp[N] = dp[i*i] + dp[N - i*i]
* 
* dp[N] -> 위의 것중에 min!
* 
*/