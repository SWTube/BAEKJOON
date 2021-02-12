#include <iostream>
#define MOD 1000000000
using namespace std;
int main(){
	int n; cin >> n;
	int DP[101][11] = { 0, }; // row : 0~100, col : 0~10

	for (int j = 1; j <= 9; j++) {
		DP[1][j] = 1;
	}

	for (int i = 2; i <= n; i++) {
		DP[i][0] = DP[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
		}
	}

	int sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += DP[n][j];
		sum %= MOD;
	}

	cout << sum % MOD;
	return 0;
}