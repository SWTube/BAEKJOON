#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, MAX = 0; // 총 회의 개수, 회의실을 사용할 수 있는 회의 개수
vector<pair<int, int>> board; // (start time, end time)

bool compare(pair<int, int>& a, pair<int, int>& b) {
	// second값으로 비교하고 > 만약 second값이 같다면 > first값으로 비교
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int greedy() {
	int cnt = 1, end = board[0].second;
	for (int i = 1; i < n; i++) {
		if (end <= board[i].first) {
			cnt++;
			end = board[i].second;
		}
	}
	MAX = max(MAX, cnt);
	return MAX;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		board.push_back(make_pair(start, end));
	}
	sort(board.begin(), board.end(), compare);
	greedy();
	cout << MAX;
	return 0;
}