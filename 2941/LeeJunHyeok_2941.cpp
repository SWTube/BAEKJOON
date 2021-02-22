#include <iostream>

using namespace std;

int main() {
	string words;
	cin >> words;

	int word_num = 0;

	for (int i = 1; i < words.length(); ++i) {
		if (words[i] == '=') {
			if (words[i - 1] == 'c' || words[i - 1] == 's') {
				++word_num;
			}
			else if (words[i - 1] == 'z') {
				if (i == 1) {
					++word_num;
				}
				else if (words[i - 2] == 'd') {
					word_num += 2;
				}
				else {
					++word_num;
				}
			}
		}
		else if (words[i] == '-') {
			if (words[i - 1] == 'c' || words[i - 1] == 'd') {
				++word_num;
			}
		}
		else if (words[i] == 'j') {
			if (words[i - 1] == 'l' || words[i - 1] == 'n') {
				++word_num;
			}
		}
	}

	cout << words.length() - word_num;

	return 0;
}