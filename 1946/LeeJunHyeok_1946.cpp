#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> doc_rank[100000];

int main() {
	int T, N = 1;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		int a, b;
		int num = 0;

		for (int j = 0; j < N; ++j) {
			cin >> doc_rank[j].first >> doc_rank[j].second;
		}

		sort(doc_rank, doc_rank + N);
		int min = doc_rank[0].second;

		for (int k = 1; k < N; ++k) {
			if (doc_rank[k].second > min) {
				++num;
			}
			else {
				min = doc_rank[k].second;
			}
		}
		cout << N- num << endl;
	}
	return 0;
}