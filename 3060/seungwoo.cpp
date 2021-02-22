#include <iostream>
#include <vector>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;
	std::vector<int> v(6);

	for (int tc = 0; tc < T; tc++) {
		int N; std::cin >> N;
		int sum = 0;

		for (int i = 0; i < 6; i++) {
			std::cin >> v[i];
			sum += v[i];
		}

		int ans = 0;

		while (true) {
			ans++;

			if (N - (sum * (int)pow(4, ans - 1)) < 0) {
				break;
			}
		}
		
		std::cout << ans << "\n";
	}

	return 0;
}