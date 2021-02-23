#include <iostream>

using namespace std;

int arr[101];
int sum[101];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i <= N - K; ++i) {
		int num = arr[i];
		int k = K;
		for (int j = i + 1; k > 1;++j) {
			num += arr[j];
			--k;
		}
		sum[i] = num;
	}

	int answer = -99999999;

	for (int i = 0; i <= N - K; ++i) {
		answer = max(answer, sum[i]);
	}

	cout << answer;

	return 0;
}