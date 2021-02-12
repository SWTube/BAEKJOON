#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int N;
int T;
int P;
int ans = 0;
std::pair<int, int> reserved[501];
int seat[101] = { 0, };
std::vector<int> indexv;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::cin >> N >> T >> P;

	for (int i = 0; i < T; i++) {
		int a;
		int b;
		std::cin >> a >> b;
		// start: 540, end: 1260
		reserved[i].first = (a / 100) * 60 + a % 100;
		reserved[i].second = (b / 100) * 60 + b % 100;
	}

	std::sort(reserved, reserved + T);

	int count1 = 0, count2 = 0;
	int index = 0;
	for (int i = 540; i < 1260; i++) {
		auto iter = indexv.begin();
		while (iter != indexv.end()) {
			if (seat[*iter] == i) {
				iter = indexv.erase(iter);
			}
			else {
				iter++;
			}
		}

		while (index < T && reserved[index].first == i) {
			if (reserved[index].first == reserved[index].second) {
				// pass
			}
			else if (indexv.empty()) {
				indexv.push_back(1);
				seat[1] = reserved[index].second;
			}
			else {
				std::sort(indexv.begin(), indexv.end());

				int findindex = -1;
				int diff = indexv[0] -1;
				for (int j = 0; j < indexv.size() - 1; j++) {
					int avg = (indexv[j + 1] - indexv[j]) / 2;
					if (avg > diff) {
						findindex = j;
						diff = avg;
					}
				}

				if (N - indexv.back() > diff) {
					indexv.push_back(N);
					seat[N] = reserved[index].second;
				}
				else if (findindex == -1) {
					indexv.push_back(1);
					seat[1] = reserved[index].second;
				}
				else {
					int ansindex = indexv[findindex] + diff;
					indexv.push_back(ansindex);
					seat[ansindex] = reserved[index].second;
				}
			}

			index++;
		}

		if (seat[P] <= i) {
			ans++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}



/*
#include <iostream>
#include <algorithm>
#include <vector>

int N;
int T;
int P;
std::vector<std::pair<int, int>> reserved;
std::vector<std::pair<bool, int>> seat;
// seat's int is endtime

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::cin >> N >> T >> P;

	reserved.resize(T);

	for (int i = 0; i < T; i++) {
		int a;
		int b;
		std::cin >> a >> b;
		// start: 540, end: 1260
		reserved[i].first = (a / 100) * 60 + a % 100;
		reserved[i].second = (b / 100) * 60 + b % 100;
	}

	std::sort(reserved.begin(), reserved.end());

	seat.resize(N + 1);
	std::vector<int> seatindex;
	int ans = 0;
	int difftime = 540;

	for (int i = 0; i < reserved.size(); i++) {
		auto iter = seatindex.begin();
		while (iter != seatindex.end()) {
			if (seat[*iter].second >= reserved[i].second) {
				seat[*iter].first = false;
				seatindex.erase(iter);
			}
			iter++;
		}

		if (reserved[i].first == reserved[i].second) {
			// pass
		}
		else if (!seat[1].first) {
			seat[1].first = true;
			seat[1].second = reserved[i].second;
			seatindex.push_back(1);
		}
		else if(!seat[N].first) {
			seat[N].first = true;
			seat[N].second = reserved[i].second;
			seatindex.push_back(N);
		}
		else {
			std::sort(seatindex.begin(), seatindex.end());

			int findindex = 0;
			int diff = 0;
			for (int j = 0; j < seatindex.size() - 1; j++) {
				int avg = (seatindex[j + 1] - seatindex[j]) / 2;

				if (avg > diff) {
					findindex = j;
					diff = avg;
				}
			}

			int index = seatindex[findindex] + diff;
			seat[index].first = true;
			seat[index].second = reserved[i].second;
			seatindex.push_back(index);
		}

		if (seat[i].first) {
			ans += reserved[i].first - difftime;
			difftime = reserved[i].first;
		}
	}

	std::cout << ans << "\n";

	return 0;
}
*/