#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> pos;
	std::vector<int> neg;
	int one = 0;
	int zero = 0;

	for (int i = 0; i < N; i++) {
		int num; std::cin >> num;

		if (num == 1) {
			one++;
		}
		else if (num > 1) {
			pos.push_back(num);
		}
		else if (num < 0) {
			neg.push_back(num);
		}
		else {
			zero++;
		}
	}
	
	if (pos.size() % 2 == 1) {
		pos.push_back(1);
	}

	if (neg.size() % 2 == 1) {
		if (zero != 0) {
			neg.push_back(0);
		}
		else {
			neg.push_back(1);
		}
	}

	std::sort(pos.begin(), pos.end());
	std::sort(neg.begin(), neg.end());

	long long ans = 0;

	for (int i = 0; i < pos.size(); i += 2) {
		ans += pos[i] * pos[i + 1];
	}
	for (int i = 0; i < neg.size(); i += 2) {
		ans += neg[i] * neg[i + 1];
	}

	ans += one;

	std::cout << ans << "\n";

	return 0;
}