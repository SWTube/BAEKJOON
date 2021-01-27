/*
 N���� �������� ���̷� �׸��� ������ �����ߴ�. �������� ���̷� �����ٰ� �׻� �� �׸��� �� ���̴� ���� �ƴϴ�. �� �׸��� ���� �κ� ���� 
 M�� ������ ���̰� �÷��� ������ �׸��� �� �κп��� ���̰� �ȴ�.
*/

#include <iostream>

using namespace std;

int arr[101][101];

int main() {
	
	int N = 0, M = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	int result = 0;

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = 0; j <= x2 - x1; ++j) {
			for (int k = 0; k <= y2 - y1; ++k) {
				arr[x1 + j][y1 + k] += 1;
			}
		}
	}

	for (int i = 1; i <= 100; ++i) {
		for (int j = 1; j <= 100; ++j) {
			if (arr[i][j] > M) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}