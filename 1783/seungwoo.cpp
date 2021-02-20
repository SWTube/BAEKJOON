#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int M;
	std::cin >> N >> M;

	int ans = 0;

	// n = 2;
	//  m <= 2; 1
	//  m <= 4; 2
	//  .
	//  m >= 9; 4
	// n = 3;
	//  if m < 7; 4
	//  else m; m - 2
	if (N == 1) {
		ans = 1;
	}
	else if (N == 2) {
		ans = std::min(4, (M + 1) / 2);
	}
	else {
		if (M < 7) {
			ans = std::min(4, M);
		}
		else {
			ans = M - 2;
		}
	}

	std::cout << ans << "\n";

	return 0;
}