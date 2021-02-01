#include <iostream>
#include <cmath>
using namespace std;

int getNum(string str){
	int num = 0;
	for(int i=0; i<str.length(); i++){
		num += int(str[i] - '0')*pow(10,str.length()-i-1);
	}
	return num;
}

int main() {
	string str, num;
	int add=0,sub=0;
	bool minus = false;
	cin >> str;
	int len = str.length();
	for(int i=0; i<=len; i++){
		if(str[i] == '-' || str[i] == '+' || i==len){
			if(minus)
				sub += getNum(num);
			else
				add += getNum(num);
			num = "";
			if(i != len && str[i]=='-')
				minus = true;
		}
		else
			num.append(1,str[i]);
	}
	cout << add-sub;
	return 0;
}