#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> alphabet(26, -1);

	string str;
	cin >> str;

	
	for (unsigned i = 0; i < str.size(); i++) {
		if (alphabet[str[i] - 'a'] != -1)
			continue;
		alphabet[(str[i] - 'a')] = i;
	}

	for (unsigned i = 0; i < 26; i++) {
		cout << alphabet[i] << ' ';
	}
}