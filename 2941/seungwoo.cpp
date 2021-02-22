#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string str; std::cin >> str;
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'c') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == '=') {
				ans++;
				i++;
			}
			else if (str[i + 1] == '-') {
				ans++;
				i++;
			}
			else {
				ans++;
			}
		}
		else if (str[i] == 'd') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == '-') {
				ans++;
				i++;
			}
			else if (str[i + 1] == 'z') {
				if (i + 2 >= str.length()) {
					ans += 2;
					break;
				}
				else if (str[i + 2] == '=') {
					ans++;
					i += 2;
				}
				else {
					ans++;
				}
			}
			else {
				ans++;
			}
		}
		else if (str[i] == 'l') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == 'j') {
				ans++;
				i++;
			}
			else {
				ans++;
			}
		}
		else if (str[i] == 'n') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == 'j') {
				ans++;
				i++;
			}
			else {
				ans++;
			}
		}
		else if (str[i] == 's') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == '=') {
				ans++;
				i++;
			}
			else {
				ans++;
			}
		}
		else if (str[i] == 'z') {
			if (i + 1 >= str.length()) {
				ans++;
				break;
			}
			else if (str[i + 1] == '=') {
				ans++;
				i++;
			}
			else {
				ans++;
			}
		}
		else {
			ans++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}