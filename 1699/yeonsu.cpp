#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> square;

int main() {
	int n; cin >> n;
	vector<int> DP;
	for (int i = 0; i <= n; i++) DP.push_back(i); // 1^2�� ������ ��Ÿ���ٰ� �����ϰ� �ʱ�ȭ�ϱ�

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[n];
	return 0;
}