#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	int MAX = -10001;
	for (int i = 0; i < N - K + 1; i++) {
		int sum = 0;
		for (int j = i; j < i + K; j++) {
			sum += v[j];
		}
		MAX = max(MAX, sum);
	}

	cout << MAX;
	return 0;
}