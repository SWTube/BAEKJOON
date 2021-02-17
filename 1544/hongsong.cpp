#include <iostream>
#include <vector>
#include <cstring>

std::string getString(std::vector<char> temp) {
	std::string str = "";
	for (int i = 0; i < temp.size(); i++) {
		str += temp[i];
	}
	return str;
}

int main() {
	int n;
	std::vector<std::string> word;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (word.empty())
			word.push_back(str);
		else {
			std::vector<char> temp;
			bool check = false;

			for (int j = 0; j < str.size(); j++)
				temp.push_back(str[j]);

			for (int j = 0; j < word.size(); j++) {
				for (int k = 0; k < temp.size(); k++) {
					std::string tempStr = getString(temp);
					if (tempStr == word[j]) {
						check = true;
						break;
					}
					char tempWord;
					auto iter = temp.begin();
					tempWord = temp[0];
					temp.erase(iter);
					temp.push_back(tempWord);
				}
				if (check)
					break;
			}
			if (!check)
				word.push_back(str);
		}
	}
	std::cout << word.size();
	return 0;
}