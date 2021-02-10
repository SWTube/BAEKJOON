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
		// ���������� �κ��� + ���簪 vs ���簪 �� ū ���� ���Ѵ�
		DP[i] = max(DP[i - 1] + numbers[i], numbers[i]);

		// ���� ���� �κ��� vs ���� �κ����� �ִ� �� ū ���� ���Ѵ�
		ans = max(DP[i], ans);
	}
	cout << ans;
	return 0;
}