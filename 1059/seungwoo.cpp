#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	
	int L; std::cin >> L;
	std::vector<int> v(L);
	bool issame = false;

	for (int i = 0; i < L; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	int n; std::cin >> n;

	for (int i = 0; i < L; i++) {
		if (v[i] == n) {
			issame = true;
			break;
		}
	}

	if (issame) {
		std::cout << 0 << "\n";
	}
	else {
		int start = 0;
		int end = 0;

		for (int i = 0; i < L; i++) {
			if (v[i] > n) {
				start = v[i - 1];
				end = v[i];
				break;
			}
		}

		int ans = 0;

		for (int i = start + 1; i < end; i++) {
			for (int j = i + 1; j < end; j++) {
				// std::cout << i << " " << j << "\n";
				if (i <= n && n <= j) {
					ans++;
				}
			}
		}

		std::cout << ans << "\n";
	}

	return 0;
}