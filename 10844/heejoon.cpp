#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int Case[101][10];
	int sum = 0;
	
	for (int j = 0; j < 10; j++)
		Case[0][j] = 0;

	for (int j = 1; j < 10; j++)
		Case[1][j] = 1;
	Case[1][0] = 0;

	for (int i = 2; i <= n; i++) { // Case[i][j] -> i는 n. j는 1의 자리 숫자
		for (int j = 0; j <= 9; j++) {
			if(j==0){
				Case[i][j] = Case[i-1][j+1];
			}
			else if (j==9){
				Case[i][j] = Case[i - 1][j-1];
 			}
			else{
				Case[i][j] = (Case[i - 1][j - 1] + Case[i - 1][j + 1]);
			}
		}
	}

	for (int j = 0; j < 10; j++) {
		sum =  (sum + Case[n][j]);
	}

	cout << sum;
}
