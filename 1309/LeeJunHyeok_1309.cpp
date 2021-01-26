#include <iostream>

using namespace std;

int arr[100001];

int main() {

	arr[1] = 3;
	arr[2] = 7;

	int N;

	cin >> N;

	if (N >= 3) {
		for (int i = 1; i <= N - 2; ++i) {
			arr[i + 2] = (arr[i + 1] * 2 + arr[i]) % 9901;
		}
	}

	cout << arr[N];

	return 0;
}