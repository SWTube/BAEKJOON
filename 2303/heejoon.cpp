#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int maxsum = 0;
	int temp, index = 0;
	bool same = false;
	vector<vector<int>> v(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> v[i][j];
		}
	}

	
	for (int row = 0; row < n; row++) {
		temp = maxsum;
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				for (int k = j + 1; k < 5; k++) {
					sum = (v[row][i] + v[row][j] + v[row][k]) % 10; 
					if (sum > maxsum) { maxsum = sum; }
					if (sum == maxsum) { same = true; }
				}
			}
		}
		if (temp != maxsum) {
			index = row;
		}
		if (same) {
			index = row;
			same = false;
		}
	}

	cout << index+1;
}