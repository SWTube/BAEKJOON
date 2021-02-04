#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	string str;
	cin >> str;

	int result = 0;
	bool minusFlag = false;
	string strToNum = "";

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == NULL) {
			if (minusFlag)
				result -= stoi(strToNum);
			else
				result += stoi(strToNum);

			strToNum = "";

			if (str[i] == '-')
				minusFlag = true;

			continue;
		}

		strToNum += str[i];
	}

	cout << result << endl;
	
	return 0;
}