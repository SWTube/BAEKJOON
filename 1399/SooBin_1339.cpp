#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


bool compare(int a, int b) {
	return a > b;
}
int main() {
	vector<int> alphabet(26, 0);

	int num;
	cin >> num;
	int maxNum = 0;
	int aNum = (int)'A';

	for (int i = 0; i < num; i++) {
		string t;
		cin >> t;
		int len = t.length()-1;
		if (maxNum < len) maxNum = len;
		for (int j = 0; j <= len; j++) {
			int seat = (int)t[j] - aNum;
			alphabet[seat] += pow(10, len-j);
		}

	}
	sort(alphabet.begin(),alphabet.end(),compare);
	int result = 0;
	int curNum = 9;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0) break;
		result += curNum * alphabet[i];
		curNum--;
	}
	cout << result;
}