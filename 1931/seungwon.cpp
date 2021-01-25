#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(b, a));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int lastNum = -1;
	for (const auto& index : v) {
		if (lastNum <= index.second) {
			lastNum = index.first;
			ans++;
		}
	}
	cout << ans;
}
