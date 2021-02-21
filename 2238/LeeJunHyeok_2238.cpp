#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> arr[100001];

bool Acending(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

bool Acending2(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int U;
	cin >> U;

	int N;
	cin >> N;

	string name;
	int money;

	vector<pair<string, int>> v;

	for (int i = 0; i < N; ++i) {
		cin >> name >> money;
		v.push_back({ name, money });
	}

	stable_sort(v.begin(), v.end(), Acending);

	string answerName;
	int answerMoney;
	bool truelyEnd = false;

	for (int i = 0; i < N - 2; ++i) {
		if (v[i].second == v[i + 1].second) {
			if (i == N - 3) {
				if (v[i + 1].second < v[i + 2].second) {
					answerName = v[i + 2].first;
					answerMoney = v[i + 2].second;
					truelyEnd = true;
					break;
				}
			}
			else {
				continue;
			}
		}
		else if (v[i].second < v[i + 1].second) {
			if (i == 0) {
				answerName = v[i].first;
				answerMoney = v[i].second;
				truelyEnd = true;
				break;
			}
			else if (v[i + 2].second > v[i + 1].second) {
				answerName = v[i + 1].first;
				answerMoney = v[i + 1].second;
				truelyEnd = true;
				break;
			}
			else {
				continue;
			}
		}
	}

	if (truelyEnd) {
		cout << answerName << ' ' << answerMoney;
	}
	else {
		for (int i = 0; i < N; ++i) {
			arr[v[i].second].first = v[i].second;
			arr[v[i].second].second += 1;
		}
		
		stable_sort(arr, arr + N, Acending2);

		int j;

		for (int i = N - 1; i >= 0; --i) {
			if (arr[i].first == 0) {
				j = i + 1;
				break;
			}
		}

		for (int i = 0; i < N; ++i) {
			if (arr[j].first == v[i].second) {
				cout << v[i].first << ' ' << v[i].second;
				break;
			}
		}
	}

	return 0;
}