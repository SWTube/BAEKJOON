#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int num; std::cin >> num;
	std::vector<int> v(num);

	for (int i = 0; i < num; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	std::cout << v[0] * v[v.size() - 1] << "\n";

	return 0;
}