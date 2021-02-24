#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int count = 0;
	string str;
	cin >> str;
	for(int i=0; i<str.size(); i++){
		if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '='){
				i+=2;
		}
		else if(((str[i] == 'c' || str[i] == 'd') && str[i+1] == '-') || ((str[i] == 'l' || str[i] == 'n') && str[i+1] == 'j') || ((str[i] == 'c' || str[i] == 's' || str[i] == 'z') && str[i+1] == '=')){
			i++;
		}
		count++;
	}
	cout << count;
	return 0;
}