#include <iostream>
#include <vector>

bool prime[1000001] = { false, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	for (int i = 2; i * i <= 1000000; i++) {
		if (!prime[i]) {
			for (int j = i * i; j <= 1000000; j+=i) {
				prime[j] = true;
			}
		}
	}

	while (true) {
		int n;
		std::cin >> n;

		if (n == 0)
			break;

		for (int i = 2; i <= 1000000; i++) {
			if (!prime[i]) {
				int secValue = n - i;

				if (!prime[secValue]) {
					std::cout << n << " = " << i << " + " << secValue << "\n";
					break;
				}
			}
		}
	}

	return 0;
}