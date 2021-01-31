#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l,p,v;
	for(int i=1; ; i++){
		cin >> l >> p >> v;
		if(!l && !p && !v)
			break;
		else{
			int days;
			days = (v/p)*l + min(v%p,l);
			cout << "Case " << i << ": " << days << "\n"; 
		}
	}
	return 0;
}