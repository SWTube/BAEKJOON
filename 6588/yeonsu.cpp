#include <iostream>
using namespace std;

int num;
const int MAX = 1000000;
int numbers[MAX + 1];

void find_prime() { // 에라토스테네스의 체 알고리즘
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

void Goldbach() { // 골드바흐 가설
	bool chk = false; // init

	for (int i = 0; i < num; i++) {
		if (numbers[i] == i && numbers[num - i] == num - i) {
			cout << num << " = " << i << " + " << (num - i) << "\n";
			chk = true; // 두 홀수 소수의 합으로 나타낼 수 있음
			return;
		}
	}

	if (chk == false) cout << "Goldbach's conjecture is wrong." << "\n"; // 두 홀수 소수의 합으로 나타낼 수 없음
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	find_prime();

	while (true) {
		cin >> num;
		if (num == 0) break; // 탈출 조건
		Goldbach();
	}
	return 0;
}