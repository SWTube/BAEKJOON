#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, p[10001], R[10001];
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> p[i];
	}
	
	//R[1] = p[1];
	//R[2] = max(2p[1], p[2]);
	//R[3] = max(3p[1], R[1] + R[2], p[3])
	//R[4] = max(4p[1], R[1] + R[3], 2R[2], p[4])
	//R[5] = amx(5p[1], R[1] + R[4], R[2] + R[3], p[5]);
	//R[i] = max(ip[1], R[1] + R[i-1], R[2] + R[i-2], ... , p[i]);
	
	R[1] = p[1];
	for(int i=2; i<=n; i++){
		int cache = max(i*p[1],p[i]);
		for(int j=1; j <= i-j; j++){
			R[i] = max(max(cache,R[j] + R[i-j]),R[i]);
		}
	}
	cout << R[n];
	return 0;
}