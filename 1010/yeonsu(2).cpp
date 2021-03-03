#include <iostream>
#define MAX 31
using namespace std;
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m; cin >> n >> m;

		int DP[MAX][MAX] = { 0, };

		for (int i = 1; i < MAX; i++) {
			DP[i][1] = i;
		}

		for (int i = 2; i < MAX; i++) {
			for (int j = 2; j < MAX; j++) {
				DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
			}
		}

		cout << DP[m][n] << "\n";
	}
	return 0;
}