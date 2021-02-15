#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; numbers.push_back(num);
	}
	sort(numbers.begin(), numbers.end()); // 오름차순

	int ans = 0, left = 0, right = n - 1;

	// 음수 : 1보다 작은 두 수를 곱하면 항상 최대
	for (left; left < right; left += 2) {
		if (numbers[left] < 1 && numbers[left + 1] < 1) {
			ans += numbers[left] * numbers[left + 1];
		}
		else break;
	}

	// 양수 : 1보다 큰 두 수를 곱하면 항상 최대
	for (right; right > 0; right -= 2) {
		if (numbers[right] > 1 && numbers[right - 1] > 1) {
			ans += numbers[right] * numbers[right - 1];
		}
		else break;
	}

	// 처리되지 못한 수들은 단순히 더한다
	for (left; left <= right; left++) {
		ans += numbers[left];
	}

	cout << ans;
	return 0;
}