#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	int chess[8][8] = { 0, };
	int start_row, dst_row;
	char _start_col, _dst_col;
	int row_meet, col_meet;
	cin >> T;
	

	for (int i = 0; i < T; i++) {
	
		cin >> _start_col >> start_row >> _dst_col >> dst_row;
		int start_col = _start_col - 'A';
		int dst_col = _dst_col - 'A';
		start_row--; dst_row--;

		// 시작점, 도착점 동일
		if (start_row == dst_row && start_col == dst_col) {
			cout << 0 << " " << char(start_col+65) << " " << start_row + 1 <<  endl;
			continue;
			}

		// 불가능 한 경우
		if ((abs(start_row - dst_row) % 2) != (abs(start_col - dst_col) % 2)) {
			cout << "Impossible" << endl;
			continue;
		}

		// 가능한 경우
		else {
				// 시작점 기준 좌우대각선!
				for (int i = 1; i < 8; i++) { // 1부터 시작이라 중복 걱정 X
					if ((start_col - i >= 0) && (start_row + i < 8)) {
						chess[start_row + i][start_col - i] += 1; // 북서 대각선
					}
					else if ((start_row - i >= 0) && (start_col - i >= 0)) {
						chess[start_row - i][start_col - i] += 1; // 남서 대각선
					}
					else if ((start_row + i < 8) && (start_col + i < 8)) {
						chess[start_row + i][start_col + i] += 1; // 북동 대각선
					}
					else if ((start_col + i < 8) && (start_row - i >= 0)) {
						chess[start_row - i][start_col + i] += 1; // 남동 대각선
					}
				}


				// 도착점 기준 좌우대각선!
				for (int i = 1; i < 8; i++) {
					if ((dst_col - i >= 0) && (dst_row + i < 8)) {
						chess[dst_row + i][dst_col - i] += 1; // 북서 대각선
					}
					else if ((dst_row - i >= 0) && (dst_col - i >= 0)) {
						chess[dst_row - i][dst_col - i] += 1; // 남서 대각선
					}
					else if ((dst_row + i < 8) && (dst_col + i < 8)) {
						chess[dst_row + i][dst_col + i] += 1; // 북동 대각선
					}
					else if ((dst_col + i < 8) && (dst_row - i >= 0)) {
						chess[dst_row - i][dst_col + i] += 1; // 남동 대각선
					}
				}

				// 두 경로의 교점 찾기!
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						if (chess[i][j] == 2) {
							row_meet = i; // row
							col_meet = j; // col
						}
					}
				}

				cout << 2 << ' ' << _start_col << ' ' << start_row + 1 << ' ' << char(col_meet + 65) << ' ' << row_meet + 1 << ' ' << _dst_col << ' ' << dst_row + 1 << endl;
		}
	}
}