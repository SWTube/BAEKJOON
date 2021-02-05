#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[100000], maxValue, dp[100000];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for(int i=1; i<n; i++){
        //dp[n] = dp[i-1]+arr[i] or arr[i];
		dp[i] = max(dp[i-1]+arr[i],arr[i]);
	}
	maxValue = dp[0];
	for(int i=1; i<n; i++){
		maxValue = max(maxValue,dp[i]);
	}
	cout << maxValue;
	return 0;
}