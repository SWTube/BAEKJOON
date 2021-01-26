#include <iostream>
#include <string>

int alphCount[26];

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string s; std::cin >> s;

	// initialization
	for (int i = 0; i < 26; i++) {
		alphCount[i] = -1;
	}

	for (int i = 97; i <= 122; i++) {
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == i) {
				alphCount[i - 97] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		std::cout << alphCount[i] << " ";
	}
	std::cout << "\n";

	return 0;
}