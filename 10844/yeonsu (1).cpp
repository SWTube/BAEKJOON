#include <iostream>
#define MOD 1000000000
using namespace std;

int n; // 자릿수 (100자리까지 가능)
int DP[101][10] = { 0, }; // (자릿수, last 숫자)

int main() {
	cin >> n; // input n

	for (int j = 1; j <= 9; j++) { // init
		DP[1][j] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				DP[i][j] = DP[i - 1][j + 1] % MOD;
			}
			else if (j == 9) {
				DP[i][j] = DP[i - 1][j - 1] % MOD;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
			}
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