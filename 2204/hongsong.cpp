#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string toLower(string str){
	for(int i=0; i<str.size(); i++){
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	return str;
}

int main() {
	while(1){
		int n;
		cin >> n;
		if(!n)
			break;
		else{
			pair<string,int> str[1001];
			string origin[1001];
			for(int i=0; i<n; i++){
				string temp;
				cin >> temp;
				str[i].first = toLower(temp);
				str[i].second = i;
				origin[i] = temp;
			}
			sort(str,str+n);
			cout << origin[str[0].second] << endl;
		}
	}
	return 0;
}