#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, m; cin >> n >> m; // n : ����, m : ����

	if (n == 1) { // ���ΰ� 1�� �� �湮�� �� �ִ� �ִ� ĭ���� 1�̴�.
		cout << 1;
	}
	else if (n == 2) { // ���ΰ� 2�� �� �湮�� �� �ִ� �ִ� ĭ���� 4�� (m+1)/2 �� ���� ���̴�.
		cout << min(4, (m + 1) / 2);
	}
	else {
		if (m < 7) { // ���ΰ� 7�̸��� �� �湮�� �� �ִ� �ִ� ĭ���� 4�� m �� ���� ���̴�.
			cout << min(4, m);
		}
		else { // �� ���� ��� �湮�� �� �ִ� �ִ� ĭ���� m - 7 + 5�̴�.
			cout << m - 7 + 5;
		}
	}

	return 0;
}