#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int price[100001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int U;
	int N;
	std::cin >> U >> N;
	std::vector<std::pair<std::string, int>> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i].first >> v[i].second;
		price[v[i].second]++;
	}

	int smallpricenum = 100001;

	for (int i = 1; i <= 100000; i++) {
		if (price[i] > 0) {
			smallpricenum = std::min(smallpricenum, price[i]);
		}
	}

	std::vector<int> lowtimeprice;

	for (int i = 1; i <= 100000; i++) {
		if (price[i] == smallpricenum) {
			lowtimeprice.push_back(i);
		}
	}

	std::sort(lowtimeprice.begin(), lowtimeprice.end());

	for (int i = 0; i < N; i++) {
		if (v[i].second == lowtimeprice[0]) {
			std::cout << v[i].first << " " << v[i].second << "\n";
			break;
		}
	}

	return 0;
}