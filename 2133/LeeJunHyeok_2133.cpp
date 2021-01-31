// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
// 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

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