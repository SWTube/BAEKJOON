#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= 'a' && str1[i] <= 'z') {
			str1[i] -= 32;
		}
	}

	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] >= 'a' && str2[i] <= 'z') {
			str2[i] -= 32;
		}
	}

	return (str1 < str2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	while (1) {
		cin >> n;
		
		if (n == 0) 
			break;

		vector<string> input(n);
	
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}
		
		sort(input.begin(), input.end(),compare);

		cout << input[0]<< "\n";
		input.clear();
	}

	return 0;
}

