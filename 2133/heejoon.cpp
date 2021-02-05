#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int N;
	int A[32] = { 0, };
	A[0] = 1;
	A[2] = 3;
	cin >> N; // N is always even number!
	for (int i = 4; i <= N; i++) {
		A[i] = A[i - 2] * A[2];
		for (int j = 4; j <= i; j += 2)
			A[i] += A[i-j] * 2;
	}

	cout << A[N];

}


/* Á¡È­½Ä!!
*  A[n] = A[n-2] * 3 + sum(DP[n-i]*2) + 2*3 + 2
* A[1] = 3;
* A[2] = 3*A[1] + 4 = 11

*/