#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

int alphArr[26];

int compHigh(int a, int b) {
	return a > b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string str; std::cin >> str;
		int size = 1;
		
		for (int j = 0; j < str.length(); j++) {
			alphArr[str[j] - 65] += pow(10, str.length() - j - 1);
		}
	}

	std::sort(alphArr, alphArr + 26, compHigh);

	int ans = 0;
	int weight = 9;

	for (int i = 0; i < 26; i++) {
		if (alphArr[i]) {
			ans += alphArr[i] * weight;
			weight--;
		}	
	}

	std::cout << ans << "\n";

	return 0;
}