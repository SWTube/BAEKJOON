#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int arr[1000001];
vector<int> v;
void getPrime() {
	for (int i = 2; i < 1000001; i++) {
		if (arr[i] > 1) {
			continue;
		}
		for (int j = i; j < 1000001; j += i) {
			arr[j] += 1;
		}
		if (arr[i] == 1) {
			v.push_back(i);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	getPrime();
	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (const auto& index : v) {
			if (index == 2) {
				continue;
			}
			if (arr[n - index] == 1) {
				cout << n << " = " << index << " + " << n - index << "\n";
				break;
			}
		}
	}
}
