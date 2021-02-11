#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<vector<int>> triangle;
vector<vector<int>> DP; // dp[i][j] = i번째 층에서 j인덱스의 수를 선택한 경우의 합

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			int num; cin >> num; row.push_back(num);
		}
		triangle.push_back(row);
		DP.push_back(row);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				DP[i][j] += DP[i - 1][j];
			}
			else if (j == i) {
				DP[i][j] += DP[i - 1][j - 1];
			}
			else {
				DP[i][j] = max(DP[i][j] + DP[i - 1][j], DP[i][j] + DP[i - 1][j - 1]);
			}
			ans = max(ans, DP[i][j]);
		}
	}

	cout << ans;
	return 0;
}