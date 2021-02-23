#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;
	vector<pair<int, int>> v(N);

		
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	
	for (int i = 0; i < N; i++) {
		bool disobey = false;
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (v[i].first > v[j].first) {
					if (v[i].second >= v[j].second) {
						disobey = true;
						break;
					}
				}

				else if (v[i].second > v[j].second) {
					if (v[i].first >= v[j].first) {
						disobey = true;
						break;
					}
				}
			}
		}
		if (!disobey) { cnt++; }
	}

	cout << cnt;
	
}