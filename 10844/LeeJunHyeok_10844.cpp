#include <iostream>
using namespace std;
unsigned long long arr[11][101]; // [a] a라는 숫자로 계단수가 끝나고, [b] 길이가 b임.
int main() {
	int N;
	unsigned long long result = 0;
	cin >> N;
	for (int i = 0; i < 10; ++i) {
		arr[i][1] = 1;
		arr[i][2] = 2;
	}
	arr[0][1] = 0;
	arr[0][2] = 1;
	arr[1][2] = 1;
	arr[9][2] = 1;
	for (int i = 3; i <= N; ++i) {
		arr[0][i] = arr[1][i - 1];
		for (int j = 1; j < 10; ++j) {
			arr[j][i] = (arr[j - 1][i - 1] + arr[j + 1][i - 1]) % 1000000000;
		}
	}
	for (int i = 0; i < 10; ++i) {
		result += arr[i][N];
	}
	cout << result % 1000000000;
	return 0;
}
