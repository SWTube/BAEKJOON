#include <iostream>
#include <algorithm>

using namespace std;

int five_count(int n);
int two_count(int n);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m, n, result;
	cin >> n >> m;
	
	result = min(five_count(n) - five_count(m) - five_count(n - m), two_count(n) - two_count(m) - two_count(n - m));
	cout << result;
}

int five_count(int n)
{
	int cnt = 0;
	for (long long int i = 5; n/i >= 1; i*=5) {
		cnt += n / i;
	}
	return cnt;
}


int two_count(int n)
{
	int cnt = 0;
	for (long long int i = 2; n / i >= 1; i *= 2) {
		cnt += n / i;
	}
	return cnt;
}
/*
* 2, 5의 갯수 세기!
* ?? 5의 갯수만 고려하면 왜 안될까?? 2의갯수는 5보다 항상 많을것 같은데??
*/
