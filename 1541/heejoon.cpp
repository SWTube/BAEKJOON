#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int stringtonum(string str) {
	int result = 0;
	int size = str.size();
	for (int i = 0; i < size; i++) {
		result += int(str[i] - '0') * pow(10, size - 1 - i);
	}
	return result;
}

int main() {
	string expression;
	string strnum = "";
	cin >> expression;
	expression += '\n';
	vector<int> num;
	vector<char> arith;
	int n = 0;

	for (char ch : expression) {
		if (ch == '+' || ch == '-')
		{
			arith.push_back(ch);
			num.push_back(stringtonum(strnum));
			strnum = "";
		}
		else if (ch == '\n') {
			num.push_back(stringtonum(strnum));
		}
		else {
			strnum += ch;
		}
	}

	// findindex
	int ans = 0;
	int first_minus_index = -1;
	for (int i = 0; i < arith.size(); i++) {
		// Before first '-', every element '+'
		if (arith[i] == '-') {
			first_minus_index = i;
			break;
		}
	}

	if (first_minus_index == -1) { // -존재 않거나 연산자 X
		for (int j = 0; j <= arith.size(); j++)
			ans += num[j];
	}
	else { // -연산자가 존재!
		for (int j = 0; j <= first_minus_index; j++)
			ans += num[j];
		for (int j = first_minus_index + 1; j < num.size(); j++)
			ans -= num[j];
	}

	cout << ans;
}
/*
* 반례 : 065+ 05
*/