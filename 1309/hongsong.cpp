#include <iostream>
using namespace std;

int zoo(int n);

int main() {
	int n;
	cin >> n;
	cout << zoo(n);
	return 0;
}

int zoo(int n){
	int dp[100002];
	
	dp[1] = 3;
	dp[2] = 7;
	for(int i=3; i<=n; i++){
		//dp[i] = 2*dp[i-1] - dp[i-2] + 2*dp[i-2] = dp[i-1]*2 + dp[i-2]
		dp[i] = (2*dp[i-1] + dp[i-2]) % 9901;
	}
	return dp[n];
}