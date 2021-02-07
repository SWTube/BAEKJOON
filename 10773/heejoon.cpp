#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int N;
	cin >> N;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {s.pop();}
		else {
			s.push(num);
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;
}
