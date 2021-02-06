#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum[501][501] = { 0, };
int pyramid[501][501] = { 0, };

int main() {
	int n;
	cin >> n;
	int maxsum = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> pyramid[i][j];
		}
	}

	maxsum = sum[0][0] = pyramid[0][0];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum[i][j] = sum[i-1][j] + pyramid[i][j];
			}
			else if (j == n - 1) {
				sum[i][j] = sum[i - 1][j - 1] + pyramid[i][j];
			}
			else {
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + pyramid[i][j];
			}

			maxsum = max(maxsum, sum[i][j]);
		}
	}

	cout << maxsum;

}