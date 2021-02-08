#include <iostream>
using namespace std;
int arr_a[101];
int arr_b[65];
int main() {
	int T;
	cin >> T;

	int rank = 1;
	int person = 1;
	int index = 1;
	
	for (int i = 1; i <= 6; ++i) { // rank
		for (int j = 1; j <= person; ++j) {
			arr_a[index] = rank;
			++index;
		}
		++rank;
		++person;
	}

	rank = 5120000;
	person = 1;
	index = 1;
	
	for (int i = 1; i <= 5; ++i) { // rank
		for (int j = 1; j <= person; ++j) {
			arr_b[index] = rank;
			++index;
		}
		rank /= 2;
		person *= 2;
	}

	for (int i = 0; i < T; ++i) {
		int a, b;
		cin >> a >> b;
		if (arr_a[a] == 1) {
			cout << 5000000 + arr_b[b] << '\n';
		}
		else if (arr_a[a] == 2) {
			cout << 3000000 + arr_b[b] << '\n';
		}
		else if (arr_a[a] == 3) {
			cout << 2000000 + arr_b[b] << '\n';
		}
		else if (arr_a[a] == 4) {
			cout << 500000 + arr_b[b] << '\n';
		}
		else if (arr_a[a] == 5) {
			cout << 300000 + arr_b[b] << '\n';
		}
		else if (arr_a[a] == 6) {
			cout << 100000 + arr_b[b] << '\n';
		}
		else {
			cout << arr_b[b] << '\n';
		}
	}
	return 0;
}