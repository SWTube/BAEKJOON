#include <iostream>
using namespace std;

int price2017(int rank) {
	if (rank == 0) { return 0; }
	else if (rank == 1) { return 5000000; }
	else if (rank > 1 && rank <= 3) { return 3000000; }
	else if (rank > 3 && rank <= 6) { return 2000000; }
	else if (rank > 6 && rank <= 10) { return 500000; }
	else if (rank > 10 && rank <= 15) { return 300000; }
	else if (rank > 15 && rank <= 21) { return 100000; }
	else { return 0; }
}

int price2018(int rank) {
	if (rank == 0) { return 0; }
	else if (rank == 1) { return 5120000; }
	else if (rank > 1 && rank <= 3) { return 2560000; }
	else if (rank > 3 && rank <= 7) { return 1280000; }
	else if (rank > 7 && rank <= 15) { return 640000; }
	else if (rank > 15 && rank <= 31) { return 320000; }
	else { return 0; }
}

int main() {
	int T;
	int a, b;
	int Price;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		Price = price2017(a) + price2018(b);
		cout << Price << endl;
	}
}