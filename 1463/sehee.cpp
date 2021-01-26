#include <iostream>
using namespace std;

int num[1000001];

int main() {
	int input;
	
	cin >> input;

	num[0] = num[1] = 0;

	if (input > 1) {
		for (int i = 2; i <= input; i++) {
			num[i] = num[i - 1] + 1;

			if (i % 2 == 0)
				num[i] = min(num[i / 2] + 1, num[i]);
			if (i % 3 == 0) 
				num[i] = min(num[i / 3] + 1, num[i]);
		}
	}

	cout << num[input];

	return 0;
}