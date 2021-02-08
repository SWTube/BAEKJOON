#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, MAX = 0; // �� ȸ�� ����, ȸ�ǽ��� ����� �� �ִ� ȸ�� ����
vector<pair<int, int>> board; // (start time, end time)

bool compare(pair<int, int>& a, pair<int, int>& b) {
	// second������ ���ϰ� > ���� second���� ���ٸ� > first������ ��
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