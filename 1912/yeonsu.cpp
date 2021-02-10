#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, MIN = -1000000000, ans;
vector<int> numbers;
vector<int> DP;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; numbers.push_back(num);
		DP.push_back(MIN);
	}

	DP[0] = numbers[0]; ans = DP[0];
	for (int i = 1; i < n; i++) {
		// 직전까지의 부분합 + 현재값 vs 현재값 중 큰 값을 택한다
		DP[i] = max(DP[i - 1] + numbers[i], numbers[i]);

		// 새로 구한 부분합 vs 이전 부분합의 최댓값 중 큰 값을 택한다
		ans = max(DP[i], ans);
	}
	cout << ans;
	return 0;
}