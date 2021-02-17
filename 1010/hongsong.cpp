// DP
#include <iostream>
using namespace std;
int arr[30][30];

int main() {
	int t,n,m;
	cin >> t;
    for(int i=0; i<=29; i++){
		for(int j=0; j<=29; j++){
			if(j==0 || i==j)
				arr[i][j] = 1;
			else{
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
	}
	for(int i=0; i<t; i++){
		cin >> n >> m;
		if(n==m){
			cout << 1 << endl;
		}
		else if(m-n <= n){
			cout << arr[m][m-n] << endl;
		}
		else{
			cout << arr[m][n] << endl;
		}
	}
	return 0;
}

// 재귀
#include <iostream>
using namespace std;

unsigned long long int factorial(int n, int k);

int main() {
	int t,n,m;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n >> m;
		if(n==m){
			cout << 1 << endl;
		}
		else if(m-n <= n){
			cout << factorial(m,m-n) / factorial(m-n,m-n) << endl;
		}
		else{
			cout << factorial(m,n) / factorial(n,n) << endl;
		}
	}
	return 0;
}

unsigned long long int factorial(int n, int k){
	if(k==1)
		return n;
	else
		return n * factorial(n-1,k-1);
}