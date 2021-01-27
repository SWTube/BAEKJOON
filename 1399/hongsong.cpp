#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

int main() {
	std::string str;
	int value[26] = { 0, }, n, k, sum;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> str;
		for (int j = 0; j < str.length(); j++) {
			value[str[j] - 65] += pow(10, str.length() - j - 1);
		}
	}

	std::sort(value, value + 26, std::greater<int>());
	sum = 0;
	k = 9;
	for (int i = 0; i < 26; i++) {
		if (value[i] > 0) {
			sum += value[i] * k;
			k--;
		}
	}
	std::cout << sum;
}