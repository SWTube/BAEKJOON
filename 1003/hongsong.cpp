#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n,dpZero[40],dpOne[40];
		cin >> n;
		dpZero[0] = 1, dpZero[1] = 0;
		dpOne[0] = 0, dpOne[1] = 1;
		for(int j=2; j<=n; j++){
			dpZero[j] = dpZero[j-1] + dpZero[j-2];
			dpOne[j] = dpOne[j-1] + dpOne[j-2];
		}
		cout << dpZero[n] << " " << dpOne[n] << endl;
	}
	return 0;
}