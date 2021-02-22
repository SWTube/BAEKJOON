#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L, n;
	int cnt = 0;
	cin >> L;
	vector<int> input(L);
	bool duplicate = false;
	for (int i = 0; i < L; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	cin >> n;
	for (int i = 0; i < L; i++) {
		if (input[i] == n) { duplicate = true; break; }
	}
	if (duplicate) { cout << 0 << endl; }
	else {
		int before = 0, after = 0;
		for (int i = 0; i < L; i++) {
			if (input[i] > n) {
				before = input[i - 1], after = input[i]; break;
			}
		}

		for (int i = before + 1; i < after; i++) {
			for (int j = i + 1; j < after; j++) {
				if (j >= n && i <= n) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}