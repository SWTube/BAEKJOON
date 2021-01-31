#include <iostream>
#include <cstring>
using namespace std;

void reverse(string str);

int main() {
	int open = -1;
	string str, temp;
	getline(cin, str);
	for(int i=0; i<str.length(); i++){
		if(str[i] == '<' || str[i] == '>')
		{
			reverse(temp);
			temp = "";
			open *= -1;
			cout << str[i];
		}
		else if (open == 1)
			cout << str[i];
		else if(str[i] == ' ')
		{
			reverse(temp);
			cout << " ";
			temp = "";	
		}
		else
		{
			temp.append(1,str[i]);
		}
	}
	reverse(temp);
	return 0;
}

void reverse(string str) {
	string tempStr;
	for (int i = str.length()-1; i >=0; i--) {
		cout << str[i];
	}
}