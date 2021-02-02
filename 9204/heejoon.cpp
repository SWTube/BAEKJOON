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

		// ������, ������ ����
		if (start_row == dst_row && start_col == dst_col) {
			cout << 0 << " " << char(start_col+65) << " " << start_row + 1 <<  endl;
			continue;
			}

		// �Ұ��� �� ���
		if ((abs(start_row - dst_row) % 2) != (abs(start_col - dst_col) % 2)) {
			cout << "Impossible" << endl;
			continue;
		}

		// ������ ���
		else {
				// ������ ���� �¿�밢��!
				for (int i = 1; i < 8; i++) { // 1���� �����̶� �ߺ� ���� X
					if ((start_col - i >= 0) && (start_row + i < 8)) {
						chess[start_row + i][start_col - i] += 1; // �ϼ� �밢��
					}
					else if ((start_row - i >= 0) && (start_col - i >= 0)) {
						chess[start_row - i][start_col - i] += 1; // ���� �밢��
					}
					else if ((start_row + i < 8) && (start_col + i < 8)) {
						chess[start_row + i][start_col + i] += 1; // �ϵ� �밢��
					}
					else if ((start_col + i < 8) && (start_row - i >= 0)) {
						chess[start_row - i][start_col + i] += 1; // ���� �밢��
					}
				}


				// ������ ���� �¿�밢��!
				for (int i = 1; i < 8; i++) {
					if ((dst_col - i >= 0) && (dst_row + i < 8)) {
						chess[dst_row + i][dst_col - i] += 1; // �ϼ� �밢��
					}
					else if ((dst_row - i >= 0) && (dst_col - i >= 0)) {
						chess[dst_row - i][dst_col - i] += 1; // ���� �밢��
					}
					else if ((dst_row + i < 8) && (dst_col + i < 8)) {
						chess[dst_row + i][dst_col + i] += 1; // �ϵ� �밢��
					}
					else if ((dst_col + i < 8) && (dst_row - i >= 0)) {
						chess[dst_row - i][dst_col + i] += 1; // ���� �밢��
					}
				}

				// �� ����� ���� ã��!
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