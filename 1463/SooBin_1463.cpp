#include <iostream>
using namespace std;


int main() {
	int num = 0;
	int count = 0;
	cin >> num;

	int* D = new int[num+1];
	for (int i = 0; i < num+1; i++) {
		D[i] = num;
	}
	D[1] = 0;

	for (int i = 2; i <= num; i++) {
		int min = D[i-1];
		int t2 = i;
		int t3 = i;
		if (i % 3 == 0) t3 = i / 3;
		if (i % 2 == 0) t2 = i / 2;
		if (D[t3] < min) min = D[t3];
		else if (D[t2] < min) min = D[t2];

		D[i] = min+1;
	}

	cout << D[num];

	delete[] D;

}