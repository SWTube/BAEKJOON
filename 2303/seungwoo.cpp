#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> v(N);
	int topVal = 0;

	for (int tc = 0; tc < N; tc++) {
		int arr[5] = { 0, };

		for (int i = 0; i < 5; i++) {
			std::cin >> arr[i];
		}

		int maxValue = 0;
		bool breakflag = false;

		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 4; j++) {
				for (int k = j + 1; k < 5; k++) {
					if (maxValue == 9) {
						breakflag = true;
						break;
					}

					maxValue = std::max(maxValue, (arr[i] + arr[j] + arr[k]) % 10);
				}

				if (breakflag) {
					break; 
				}
			}

			if (breakflag) {
				break;
			}
		}

		v[tc] = maxValue;
		topVal = std::max(topVal, maxValue);
	}

	std::reverse(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		if (v[i] == topVal) {
			std::cout << N - i << "\n";
			break;
		}
	}

	return 0;
}