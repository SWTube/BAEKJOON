#include <iostream>
using namespace std;

int combination(int n, int k);

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T, n, m;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		cout << combination(m, n) << "\n";
	}
}

int combination(int n, int k) {

	int Pascal[31][31] = { 0, };
	
	Pascal[0][0] = 1;
	// Side
	for (int i = 1; i <= 30; i++) {
		Pascal[i][0] = 1;
		Pascal[i][i] = 1;

		for (int j = 1; j <= i; j++) {
			Pascal[i][j] = Pascal[i - 1][j - 1] + Pascal[i - 1][j];
		}
	}

	return Pascal[n][k];
}