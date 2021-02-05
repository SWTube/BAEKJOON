#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	int n, arr[501][501],dp[501][501];
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			int left,right;
			left = dp[i-1][j] + arr[i][j], right = dp[i-1][j-1] + arr[i][j];
			if(i==0)
				dp[i][j] = left;
			else if(i==j)
				dp[i][j] = right;
			else
				dp[i][j] = max(left,right);
		}
	}
	int maxValue;
	for(int i=0; i<n; i++){
		maxValue = max(maxValue,dp[n-1][i]);
	}
	cout << maxValue;
	return 0;
}