#include <iostream>
using namespace std;
// �����佺�׳׽��� ü
const int MAX = 1000000;
int prime[MAX]; // �Ҽ� ���� �迭
int pn = 0; // �Ҽ��� ����
bool check[MAX + 1]; // ���������� true

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < MAX; i++) {
		if (check[i] == false) { // �������� ����
			prime[pn++] = i;
			for (int j = i * 2; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0) { break; }
		for (int i = 0; i < MAX; i++) {
			if (check[n - prime[i]] == false) {
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}