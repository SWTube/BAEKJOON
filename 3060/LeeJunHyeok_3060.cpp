#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;

		int num;
		int day = 0;
		int total_food = 0;

		for (int j = 1; j < 7; ++j) {
			cin >> num;
			total_food += num;
		}

		int times = 1;

		while (true) {
			++day;
			if (N - (total_food * times) < 0) {
				break;
			}
			times *= 4;
		}

		cout << day << '\n';
	}

	return 0;
}