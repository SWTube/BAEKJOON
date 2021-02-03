#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int t = 0; t < T; t++) {
		int N; std::cin >> N;
		std::vector<std::pair<int, int>> v(N);

		for (int n = 0; n < N; n++) {
			std::cin >> v[n].first >> v[n].second;
		}

		std::sort(v.begin(), v.end());
		int compareRank = v[0].second;
		int ans = 1;

		for (int i = 1; i < N; i++) {
			if (compareRank > v[i].second) {
				ans++;
				compareRank = v[i].second;
			}
		}

		std::cout << ans << "\n";

	}

	return 0;
}