#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int i = 0; i < T; i++) {
		int a;
		int b;
		std::cin >> a >> b;

		int ans = 0;
		
		if (a == 0)
			ans += 0;
		else if (a == 1) 
			ans += 5000000;
		else if (a <= 3) 
			ans += 3000000;
		else if (a <= 6) 
			ans += 2000000;
		else if (a <= 10) 
			ans += 500000;
		else if (a <= 15) 
			ans += 300000;
		else if (a <= 21) 
			ans += 100000;

		if (b == 0)
			ans += 0;
		else if (b == 1)
			ans += 5120000;
		else if (b <= 3)
			ans += 2560000;
		else if (b <= 7)
			ans += 1280000;
		else if (b <= 15)
			ans += 640000;
		else if (b <= 31)
			ans += 320000;

		std::cout << ans << "\n";
	}

	return 0;
}