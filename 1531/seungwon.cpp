#include<iostream>
using namespace std;
int arr[101][101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				arr[j][k] += 1;
			}
		}
	}
	int ans = 0;
	for (const auto& x : arr) {
		for (const auto& y : x) {
			if (y > m) {
				ans += 1;
			}
		}
	}
	cout << ans;
}
