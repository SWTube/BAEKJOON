#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, dp[100001];
	cin >> n;
    dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		if(sqrt(i) == int(pow(i,0.5)))
			dp[i] = 1;
		else{
			dp[i] = 999999999;
			for(int j=1; j*j <= i; j++){
				dp[i] = min(dp[i],dp[i-j*j]+dp[j*j]);
			}
		}
	}
	cout << dp[n];
	return 0;
}