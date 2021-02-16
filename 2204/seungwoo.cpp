#include <iostream>
#include <algorithm>
#include <vector>

bool fast(std::string a, std::string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			a[i] -= 32;
		}
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] >= 'a' && b[i] <= 'z') {
			b[i] -= 32;
		}
	}

	if (a.compare(b) > 0) {
		return false;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	
	while (N != 0) {
		std::vector<std::string> v(N);

		for (int i = 0; i < N; i++) {
			std::string s; std::cin >> s;
			v[i] = s;
		}

		std::sort(v.begin(), v.end(), fast);

		std::cout << v[0] << "\n";

		std::cin >> N;
	}

	return 0;
}