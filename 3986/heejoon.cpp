#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool goodWord(string);

int main() {
	int n, count = 0;
	cin >> n;
	string Input;
	
	for (int i = 0; i < n; i++) {
		cin >> Input;
		if (goodWord(Input)) { count++; }
	}

	cout << count;
}


bool goodWord(string str) {
	stack<char> s;

	// aabb
	for (char ch : str) {
		
		if (!s.empty()) {
			if (ch == s.top()) {
				s.pop();
			}
			else {
				s.push(ch);
			}
		}
		else {
			s.push(ch);
		}
	}

	if (s.empty())
		return true;
	else {
		return false;
	}
}