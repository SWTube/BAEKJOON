#include <iostream>
#include <algorithm>
#include <vector>

int ind[100001];
std::pair<int, int> segtree[400000];

std::pair<int, int> segInit(int start, int end, int index) {
	if (start == end) {
		segtree[index].first = ind[start];
		segtree[index].second = ind[start];
		return segtree[index];
	}

	int mid = (start + end) / 2;

	std::pair<int, int> mleft = segInit(start, mid, index * 2);
	std::pair<int, int> mright = segInit(mid + 1, end, index * 2 + 1);

	segtree[index].first = std::min(mleft.first, mright.first);
	segtree[index].second = std::max(mleft.second, mright.second);

	return segtree[index];
}

std::pair<int, int> segQuery(int start, int end, int left, int right, int index) {
	if (start > right || end < left)
		return std::make_pair(1000000001, 0);
	if (left <= start && end <= right)
		return segtree[index];

	int mid = (start + end) / 2;

	std::pair<int, int> mleft = segQuery(start, mid, left, right, index * 2);
	std::pair<int, int> mright = segQuery(mid + 1, end, left, right, index * 2 + 1);

	return std::make_pair(std::min(mleft.first, mright.first), std::max(mleft.second, mright.second));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int M;
	std::cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> ind[i];
	}

	segInit(1, N, 1);

	for (int i = 0; i < M; i++) {
		int a;
		int b;
		std::cin >> a >> b;

		std::pair<int, int> ans = segQuery(1, N, a, b, 1);

		std::cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}