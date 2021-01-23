#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int reference = 0;

	std::cin >> N;

	std::vector<std::pair<int, int>> time(N);

	for (int i = 0; i < N; i++) {
		// second: start time, first: end time.
		std::cin >> time[i].second >> time[i].first;
	}

	sort(time.begin(), time.end());

	int endTime = 0;

	for (int i = 0; i < N; i++) {
		if (time[i].second >= endTime) {
			endTime = time[i].first;
			reference++;
		}
	}
	
	std::cout << reference << "\n";

	return 0;
}