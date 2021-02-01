#include <iostream>
#include <cmath>

// right-up, right-down, left-down, left-up
// like clock 
int dx[4] = { 1, 1, -1, -1 }; 
int dy[4] = { 1, -1, -1, 1 };
bool board[9][9];
char sx;
int sy;
char ex;
int ey;

char bufx;
int bufy;

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x - 'A' + 1;
		int ny = y;

		while (true) {
			nx += dx[i];
			ny += dy[i];

			if (nx > 0 && ny > 0 && nx < 9 && ny < 9) {
				if (board[nx][ny]) {
					bufx = nx + 'A' - 1;
					bufy = ny;
					return;
				}
			}
			else
				break;
		}
	}
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int t = 0; t < T; t++) {
		std::cin >> sx >> sy >> ex >> ey;

		int count = 0;

		if ((abs(sx - ex) + abs(sy - ey)) % 2 == 1) {
			std::cout << "Impossible\n";
			continue;
		}
		else if (sx == ex && sy == ey) {
			std::cout << count << " " << sx << " " << sy << "\n";
			continue;
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				board[i][j] = false;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = ex - 'A' + 1;
			int ny = ey;

			while (true) {
				nx += dx[i];
				ny += dy[i];

				if (nx > 0 && ny > 0 && nx < 9 && ny < 9) {
					board[nx][ny] = true;
					// std::cout << nx << " " << ny << "\n";
				}
				else
					break;
			}
		}
		count++;

		// std::cout << sx - 'A' + 1 << " " << sy << std::endl;
		if(board[sx - 'A' + 1][sy])
			std::cout << count << " " << sx << " " << sy << " " << ex << " " << ey << "\n";
		else {
			count++;
			func(sx, sy);
			std::cout << count << " " << sx << " " << sy << " ";
			std::cout << bufx << " " << bufy << " ";
			std::cout << ex << " " << ey << "\n";
		}

	}

	return 0;
}