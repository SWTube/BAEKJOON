#include <iostream>
#include <algorithm>
using namespace std;
int DP[1000000] = { 0, }; // ����Ƚ���� �����ϴ� DP �迭
int main() {
	int x; cin >> x; // ���� �Է�
	for (int i = 2; i <= x; i++) { // 1�� ����Ƚ���� 0�̹Ƿ� 2���� ����
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[x]; // ��� ���
	return 0;
}