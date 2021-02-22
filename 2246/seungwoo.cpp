#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::pair<int, int>>v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	std::sort(v.begin(), v.end());

	int ans = 1;
	int D = v[0].first;
	int C = v[0].second;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[j].first > D && v[j].second < C) {
				ans++;
				D = v[j].first;
				C = v[j].second;
				break;
			}
		}
	}

	std::cout << ans << "\n";

	return 0;
}