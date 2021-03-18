/*
* 
* D[N] = 이친수의 갯수
* 
* Find 점화식! dp[][0] -> 마지막 숫자가 0
* D[N][0] = D[N-1][1] + 2
* D[N][1] = D[n-1][0] + 1
* 
* 100 D[3][0] = D[2][0]
* 101 D[3][1] = D[2][0] 
* 
* D[1] = 1
* D[2] = 1
* D[3] = 2
* D
*/

#include <iostream>

using namespace std;

long long int dp[91][2] = {0,};

int main() {
	int Input;
	cin >> Input;

	dp[1][1] = 1; // 1
	dp[2][0] = 1; // 10

	for (int N = 3; N <= Input; N++) {
		dp[N][0] = dp[N - 1][1] + dp[N-1][0];
		dp[N][1] = dp[N - 1][0];
	}

	cout << dp[Input][0] + dp[Input][1];
}
