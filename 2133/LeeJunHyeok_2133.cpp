// 3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.
// ù° �ٿ� N(1 �� N �� 30)�� �־�����.

#include <iostream>

using namespace std;
int arr[100];

int main() {
	int N;
	arr[0] = 1; arr[2] = 3;

	cin >> N;

	if (N % 2 == 1) {
		cout << 0;
	}
	else {
		for (int i = 1; i < N; ++i) {
			arr[2 * i + 2] = arr[2 * i] * 4 - arr[2 * i - 2];
		}
		cout << arr[N];
	}

	return 0;
}