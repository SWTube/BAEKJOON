#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int count = 0;
	while (true) {
		count++;

		int L;
		int P;
		int V;
		std::cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			break;

		// first:
		// ans = L * (V / P) + V % P;
		// Counterexample:
		// if remainder > L => L

		int remain = V % P;
		remain = std::min(remain, L);
		int ans = (V / P) * L + remain;

		std::cout << "Case " << count << ": " << ans << "\n";
	}

	return 0;
}