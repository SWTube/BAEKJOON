#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin >> N;
	int sum = 0;
	vector<int> glass(10003);
	vector<int> dp(10003);

	for (int i = 0; i < N; i++) {
		cin >> glass[i+3];
	}

	// dp[0].dp[1],dp[2] = 0;
	for (int i = 3; i < N+3; i++) {
		dp[i] = max(dp[i - 3] + glass[i - 1] + glass[i], dp[i - 2] + glass[i]);
		dp[i] = max(dp[i - 1], dp[i]);
		sum = max(sum, dp[i]);
	}

	cout << sum;
}

/*
* A[n-2] -> chose or A[n-2] -> not chosen!
* 
* 1) A[n-2] -> chose!
* dp[n] = A[n]+ A[n-1] + dp[n-3];
* 
* 2) A[n-2] -> not chosen!
* dp[n] = dp[n-1] or dp[n] = dp[n-2] + A[n]
*/