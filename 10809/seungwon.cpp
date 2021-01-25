#include<iostream>
#include<string>
int arr[26];
int main() {
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		arr[s[i] - 97] = (arr[s[i] - 97] == 0) ? arr[s[i] - 97] = i + 1 : arr[s[i] - 97];
	}
	for (const auto& i : arr) {
		std::cout << (i != 0 ? i - 1 : -1 ) << " ";
	}
    return 0;
}
