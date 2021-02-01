#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, sum = 0, min;
		cin >> n;
		vector<pair<int, int>> arr;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			arr.push_back({ a,b });
			sum++;
		}
		sort(arr.begin(), arr.end());
		min = arr[0].second;
		for (int j = 0; j < n; j++) {
			if (min < arr[j + 1].second)
				sum--;
			else
				min = arr[j + 1].second;
		}
		cout << sum << "\n";
	}
	return 0;
}