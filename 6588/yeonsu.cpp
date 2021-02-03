#include <iostream>
using namespace std;

int num;
const int MAX = 1000000;
int numbers[MAX + 1];

void find_prime() { // �����佺�׳׽��� ü �˰���
	for (int i = 0; i < MAX + 1; i++) numbers[i] = i;

	for (int i = 2; i * i < MAX + 1; i++) {
		if (numbers[i] == i) {
			for (int j = i * i; j < MAX + 1; j += i) {
				if (numbers[j] == j) numbers[j] = i;
			}
		}
	}
	numbers[0] = -1; numbers[1] = -1;

	//for (int i = 0; i < MAX + 1; i++) { // for check
	//	if (numbers[i] == i) cout << i << " ";
	//}
	//cout << endl;
}

void Goldbach() { // ������ ����
	bool chk = false; // init

	for (int i = 0; i < num; i++) {
		if (numbers[i] == i && numbers[num - i] == num - i) {
			cout << num << " = " << i << " + " << (num - i) << "\n";
			chk = true; // �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� ����
			return;
		}
	}

	if (chk == false) cout << "Goldbach's conjecture is wrong." << "\n"; // �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� ����
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	find_prime();

	while (true) {
		cin >> num;
		if (num == 0) break; // Ż�� ����
		Goldbach();
	}
	return 0;
}