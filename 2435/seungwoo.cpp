#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int K;
	std::cin >> N >> K;
	std::vector<int> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
	}

	int max = -99999;

	for (int i = 0; i < N - K + 1; i++) {
		int sum = 0;

		for (int j = i; j < i + K; j++) {
			sum += v[j];
		}

		max = std::max(sum, max);
	}

	std::cout << max << "\n";

	return 0;
}