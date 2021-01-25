#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[10000];
	int p[1000];
	p[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			p[i] = max(p[i], p[i - j] + arr[j]);
		}
	}
	cout << p[N];
}