#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		arr[i] = arr[i - 1] + 1;
		arr[i] = (i % 2 == 0) ? min(arr[i], arr[i / 2] + 1) : arr[i];
		arr[i] = (i % 3 == 0) ? min(arr[i], arr[i / 3] + 1) : arr[i];
	}
	cout << arr[n];
}
