#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	long int num;
	int N;
	cin >> num;
	vector<int> list(num);

	for (int i = 0; i < num; i++) {
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	if (num % 2 == 1) {
		if (num == 1) { N = pow(list[0], 2); }
		else {
			N = pow(list[(num - 1) / 2], 2);
		}
	}
	else {
		N = list[0] * list[num - 1];
	}

	cout << N;
}