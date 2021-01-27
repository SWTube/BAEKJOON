#include <iostream>
#include <vector>
#define MOD 9901
using namespace std;
vector<vector<int>> DP;
int main() {
	int n; cin >> n;
	
	vector<int> row = { 0,0,0 };
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			DP.push_back({ 1,1,1 });
		}
		else DP.push_back(row);
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % MOD;
			DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % MOD;
			DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
		}
		cnt = DP[i][0] + DP[i][1] + DP[i][2];
	}

	cout << cnt % MOD;
	return 0;
}