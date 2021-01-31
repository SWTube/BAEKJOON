#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[1000002];
	int n;
	for(int i=3; i<=1000000; i+=2)
		arr[i] = true;
	for (int i = 3; i <= 1000; i += 2) {
		for (int j = i*2; j <= 1000000; j += i) {
				arr[j] = false;
		}
	}
	while(1) {
		cin >> n;
		if (n == 0)
			break;
		for (int j = 3; j < n; j += 2) {
			if (arr[j] && arr[n - j]) {
				cout << n << " = " << j << " + " << n - j << "\n";
				break;
			}
		}
	}
	return 0;
}