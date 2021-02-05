#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k;
	cin >> k;
	
	stack<int> money;
	int num;
	int result = 0;

	for (int i = 0; i < k; ++i) {
		cin >> num;
		if (num == 0) {
			money.pop();
		}
		else {
			money.push(num);
		}
	}

	while (!money.empty()) {
		result += money.top();
		money.pop();
	}

	cout << result;

	return 0;
}