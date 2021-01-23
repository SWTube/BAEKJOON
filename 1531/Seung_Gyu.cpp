#include <stdio.h>

int main() {
	int arr[100][100] = { 0, };
	int N, M;
	int bX, bY, tX, tY;
	int MaxX, MaxY, MinX, MinY;
	int covered = 0;
	scanf_s("%d %d", &N, &M);
	scanf_s("%d %d %d %d", &bX, &bY, &tX, &tY);
	MaxX = tX;
	MaxY = tY;
	MinX = bX;
	MinY = bY;
	for (int x = bX-1; x < tX; x++) {
		for (int y = bY-1; y < tY; y++) {
			arr[x][y]++;
		}
	}
	for (int i = 1; i < N; i++) {
		scanf_s("%d %d %d %d", &bX, &bY, &tX, &tY);
		if (MaxX < tX) MaxX = tX;
		if (MinX > bX) MinX = bX;
		if (MaxY < tY) MaxY = tY;
		if (MinY > bY) MinY = bY;
		for (int x = bX-1; x < tX; x++) {
			for (int y = bY-1; y < tY; y++) {
				arr[x][y]++;
			}
		}
	}
	for (int x = MinX- 1; x < MaxX; x++) {
		for (int y = MinY - 1; y < MaxY; y++) {
			if (arr[x][y] > M)
				covered++;
		}
	}
	printf("%d", covered);
	return 0;
}