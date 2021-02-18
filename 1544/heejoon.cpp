#include <iostream>
#include <string>
#include <vector>

using namespace std;

void circularString(string& str);
bool CheckSame(string, string);

int main() {
	int n, ans = 0;
	int checksamecount = 0;
	cin >> n;
	vector<string> list(n);
	
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		for (int j = 0; j < i; j++) {
			if (CheckSame(list[i], list[j])) {
				break;
			}
			else {
				checksamecount++;
			}
		}
		if (checksamecount == i) { ans++; }
		checksamecount = 0;
	}
	
	cout << ans;
}

// Makes a circularString rotating clockwise once
void circularString(string& str)
{
	char temp = str[0];
	str.erase(0,1);
	str += temp;
}

bool CheckSame(string str1, string str2)
{
	for (int i = 0; i < str1.size(); i++) {
		circularString(str1);
		if (str1 == str2) { return true; break; }
	}

	return false;
}

