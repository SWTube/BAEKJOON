#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long int n;
	long long int ans;
	cin >> n;
	if(sqrt(n) < n)
		ans = sqrt(n)+1;
	else
		ans = sqrt(n);
	cout << ans;
	return 0;
}