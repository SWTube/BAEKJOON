#include <iostream>
#include <algorithm>
using namespace std;

//int max(int a, int b) { return (a > b ? a : b); }

int main() {
	int n;
	cin >> n;

	int b;
	int maxsum;
	int sum[100000] = { 0, };
	int input[100001] = { 0, };

	for (int i = 0; i < n; i++)
		cin >> input[i];

	b = input[0];
	maxsum = input[0];
	sum[0] = input[0];

	for (int i = 0; i < n - 1; i++) {
		sum[i + 1] = sum[i] + input[i + 1];
	}
	
	
	for (int i = 0; i < n-1; i++) {
		
		b = max(input[i + 1], b + input[i+1]);
		if (maxsum < b) {
			maxsum = b;
		}
		
	}
	cout << maxsum;
}
/*
* 10vs(6 vs -4) = 10
* 10vs((6+3) vs 3) = 10
* 10 vs ((9+1) vs 1) = 10
* 15 vs ((10+5) vs 5 ) = 15
...
* 21 vs ((21-35)b vs -35) = 21
* 21 vs ((-14+12)b vs 12) = 21
* 21 vs ((12+21)b vs 21) = 33 
*/
