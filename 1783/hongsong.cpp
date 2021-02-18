#include <iostream>
using namespace std;

int main() {
	int n, m, count = 0;
	cin >> n >> m;
	if(n==2){
		if(m<=8)
			count = (m-1)/2;
		else
			count = 3;
	}
	else if(n>=3){
		if(m <= 4){
			count = m-1;
		}
		else if(m <= 6)
			count = m/2 + m%2;
		else
			count = m-3;
	}
	cout << count+1;
	return 0;
}