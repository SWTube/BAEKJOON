#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Acending(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> condo;

	int D, C;

	for (int i = 0; i < N; ++i) {
		cin >> D >> C;
		condo.push_back({ D, C });
	}

	sort(condo.begin(), condo.end(), Acending);

	int answer = 1;
	int nowD = condo[0].first, nowC = condo[0].second;

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (condo[j].first > nowD && condo[j].second < nowC) {
				++answer;
				nowD = condo[j].first;
				nowC = condo[j].second;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}