#include <iostream>
using namespace std;

int main() {
	

	int picture[101][101] = { 0, }; // 배열 0으로 초기화

	int N, M;
	int x1, y1, x2, y2;
	int sum = 0;
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				picture[x][y] ++;
				}
			}
		}
	

	for(int i=1;i <= 100;i++)
		for(int j=1;j<=100;j++)
			if (picture[i][j] >= M + 1) 
					sum ++;

	cout << sum;

}

// O(N^^2)