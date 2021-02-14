#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> square;

int main() {
	int n; cin >> n;
	vector<int> DP;
	for (int i = 0; i <= n; i++) DP.push_back(i); // 1^2의 합으로 나타낸다고 생각하고 초기화하기

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[n];
	return 0;
}