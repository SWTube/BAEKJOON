#include <iostream>
using namespace std;
int main() {
	int T; cin >> T;
	for (int t = 0; t < T; t++) {
		int n; cin >> n;

		int DP[12] = { 0, };
		DP[1] = 1; DP[2] = 2; DP[3] = 4;

		for (int i = 4; i <= n; i++) {
			DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
		}
		
		cout << DP[n] << "\n";
	}
	return 0;
}