/*
 N개의 불투명한 종이로 그림을 가리기 시작했다. 불투명한 종이로 가린다고 항상 그 그림이 안 보이는 것은 아니다. 그 그림의 현재 부분 위에 
 M개 이하의 종이가 올려져 있으면 그림은 그 부분에서 보이게 된다.
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