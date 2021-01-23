#include <iostream>
using namespace std;
// 에라토스테네스의 체
const int MAX = 1000000;
int prime[MAX]; // 소수 저장 배열
int pn = 0; // 소수의 갯수
bool check[MAX + 1]; // 지워졌으면 true

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < MAX; i++) {
		if (check[i] == false) { // 지워지지 않음
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