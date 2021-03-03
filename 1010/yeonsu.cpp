#include <iostream>
using namespace std;
int main() {
	int testcase; cin >> testcase;
	for (int x = 0; x < testcase; x++) {
		int n, m; cin >> n >> m;
		int res = 1;
		for (int i = 0; i < n; i++) {
			res *= (m - i);
			res /= (i + 1);
		}
		cout << res << "\n";
	}
	return 0;
}