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
	sort(numbers.begin(), numbers.end()); // ��������

	int ans = 0, left = 0, right = n - 1;

	// ���� : 1���� ���� �� ���� ���ϸ� �׻� �ִ�
	for (left; left < right; left += 2) {
		if (numbers[left] < 1 && numbers[left + 1] < 1) {
			ans += numbers[left] * numbers[left + 1];
		}
		else break;
	}

	// ��� : 1���� ū �� ���� ���ϸ� �׻� �ִ�
	for (right; right > 0; right -= 2) {
		if (numbers[right] > 1 && numbers[right - 1] > 1) {
			ans += numbers[right] * numbers[right - 1];
		}
		else break;
	}

	// ó������ ���� ������ �ܼ��� ���Ѵ�
	for (left; left <= right; left++) {
		ans += numbers[left];
	}

	cout << ans;
	return 0;
}