#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t,a,b, first[6] = {500,300,200,50,30,10}, second[5] = {512,256,128,64,32};
	cin >> t;
	for(int i=0; i<t; i++){
		int sum = 0;
		cin >> a >> b;
		if(a<=21 && a>0){
			for(int i=1; i<=6; i++){
				a -= i;
				if(a<=0){
					sum += first[i-1];
					break;
				}
			}
		}
		if(b<=31 && b>0){
			for(int i=0; i<5; i++){
				b -= pow(2,i);
				if(b<=0){
					sum += second[i];
					break;
				}
			}
		}
		cout << sum * 10000<< endl;
	}
	return 0;
}