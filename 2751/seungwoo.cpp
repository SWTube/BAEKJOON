#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> v(N);

	for (int i = 0; i < N; i++) {
		int num; std::cin >> num;
		v[i] = num;
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		std::cout << v[i] << "\n";
	}

	return 0;
}