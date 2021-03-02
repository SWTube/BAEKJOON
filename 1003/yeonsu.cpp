#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int DP[41][2] = { 0, };
		DP[0][0] = 1; DP[1][1] = 1;

		int N; cin >> N;
		for (int i = 2; i <= N; i++) {
			DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
			DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
		}

		cout << DP[N][0] << " " << DP[N][1] << "\n";
	}
	return 0;
}