#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n + 1);

	// A[n+2] = 2 X A[n+1] + A[n] 
	A[0] = 1;
	A[1] = 3;
	for (int i = 2; i <= n ; i++)
		A[i] = ((2 * A[i - 1]) + A[i - 2]) % 9901;
	
	cout << A[n];

}