#include <iostream>

int overlap[101][101] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; int M;
	std::cin >> N >> M;

	int ldX;
	int ldY;
	int ruX;
	int ruY;
	
	for (int i = 0; i < N; i++) {
		std::cin >> ldX >> ldY >> ruX >> ruY;

		for (int j = ldX; j <= ruX; j++) {
			for (int k = ldY; k <= ruY; k++) {
				overlap[j][k]++;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (overlap[i][j] > M) {
				ans++;
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}